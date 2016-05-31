#include <RemoteControl/DocumentPlugin.hpp>

#include <core/document/Document.hpp>
#include <core/document/DocumentModel.hpp>
#include <iscore/document/DocumentInterface.hpp>

#include <RemoteControl/Scenario/Scenario.hpp>
#include <RemoteControl/Settings/Model.hpp>


#include <Device/Node/DeviceNode.hpp>
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <QBuffer>
#include <QJsonObject>
#include <QJsonDocument>
#include <iscore/serialization/VisitorCommon.hpp>
#include <Scenario/Application/ScenarioActions.hpp>
#include <iscore/tools/ModelPathSerialization.hpp>
#include <iscore/actions/Action.hpp>
#include <State/Message.hpp>
namespace RemoteControl
{
DocumentPlugin::DocumentPlugin(
        const iscore::DocumentContext& doc,
        QObject* parent):
    iscore::DocumentPlugin{doc, "RemoteControl::DocumentPlugin", parent},
    receiver{doc, 10212}
{
    auto& set = m_context.app.settings<Settings::Model>();
    if(set.getEnabled())
    {
        create();
    }

    con(set, &Settings::Model::EnabledChanged,
        this, [=] (bool b) {
        if(b)
            create();
        else
            cleanup();
    }, Qt::QueuedConnection);
}

DocumentPlugin::~DocumentPlugin()
{
    cleanup();
}

void DocumentPlugin::create()
{
    if(m_root)
        cleanup();

    auto& doc = m_context.document.model().modelDelegate();
    auto scenar = safe_cast<Scenario::ScenarioDocumentModel*>(&doc);
    auto& cstr = scenar->baseScenario().constraint();
    m_root = new Constraint(
                getStrongId(cstr.components),
                cstr,
                *this,
                m_context,
                this);
    cstr.components.add(m_root);
}

void DocumentPlugin::cleanup()
{
    if(!m_root)
        return;

    // Delete
    auto& doc = m_context.document.model().modelDelegate();
    auto scenar = safe_cast<Scenario::ScenarioDocumentModel*>(&doc);
    auto& cstr = scenar->baseScenario().constraint();

    cstr.components.remove(m_root);
    m_root = nullptr;
}

Receiver::Receiver(
        const iscore::DocumentContext& doc,
        quint16 port):
    m_server{"i-score-ctrl",  QWebSocketServer::NonSecureMode},
    m_dev{doc.plugin<Explorer::DeviceDocumentPlugin>()}
{
    if (m_server.listen(QHostAddress::Any, port))
    {
        connect(&m_server, &QWebSocketServer::newConnection,
                this, &Receiver::onNewConnection);
    }

    m_answers.insert(std::make_pair("Trigger", [] (const QJsonObject& obj)
    {
        qDebug() << "Trigger 1";
        auto it = obj.find("Path");
        if(it == obj.end())
            return;


        qDebug() << "Trigger 2";
        auto path = unmarshall<Path<Scenario::TimeNodeModel>>(it->toObject());
        if(!path.valid())
            return;

        qDebug() << "Trigger 3";
        Scenario::TimeNodeModel& tn = path.find();
        tn.trigger()->triggeredByGui();
    }));

    m_answers.insert(std::make_pair("Message", [this] (const QJsonObject& obj)
    {
        auto it = obj.find("Message");
        if(it == obj.end())
            return;

        auto message = unmarshall<::State::Message>(it->toObject());
        m_dev.updateProxy.updateRemoteValue(message.address, message.value);
    }));


    m_answers.insert(std::make_pair("Play", [&] (const QJsonObject&)
    {
        doc.app.actions.action<Actions::Play>().action()->trigger();
    }));
    m_answers.insert(std::make_pair("Pause", [&] (const QJsonObject&)
    {
        doc.app.actions.action<Actions::Play>().action()->trigger();
    }));
    m_answers.insert(std::make_pair("Stop", [&] (const QJsonObject&)
    {
        doc.app.actions.action<Actions::Stop>().action()->trigger();
    }));
}


Receiver::~Receiver()
{
    m_server.close();
    qDeleteAll(m_clients);
}


void Receiver::registerTimeNode(Path<Scenario::TimeNodeModel> tn)
{
    if(find(m_activeTimeNodes, tn) != m_activeTimeNodes.end())
        return;

    m_activeTimeNodes.push_back(tn);

    QJsonObject mess;
    mess["Message"] = "TriggerAdded";
    mess["Path"] = toJsonObject(tn);
    QJsonDocument doc{mess};
    auto json = doc.toJson();

    for(auto client : m_clients)
    {
        client->sendTextMessage(json);
    }
}


void Receiver::unregisterTimeNode(Path<Scenario::TimeNodeModel> tn)
{
    if(find(m_activeTimeNodes, tn) == m_activeTimeNodes.end())
        return;

    m_activeTimeNodes.remove(tn);

    QJsonObject mess;
    mess["Message"] = "TriggerRemoved";
    mess["Path"] = toJsonObject(tn);
    QJsonDocument doc{mess};
    auto json = doc.toJson();

    for(auto client : m_clients)
    {
        client->sendTextMessage(json);
    }
}


void Receiver::onNewConnection()
{
    auto client = m_server.nextPendingConnection();

    connect(client, &QWebSocket::textMessageReceived,
            this, &Receiver::processTextMessage);
    connect(client, &QWebSocket::binaryMessageReceived,
            this, &Receiver::processBinaryMessage);
    connect(client, &QWebSocket::disconnected,
            this, &Receiver::socketDisconnected);

    {
        QJsonObject mess;
        mess["Message"] = "DeviceTree";
        mess["Path"] = toJsonObject(m_dev.rootNode());
        QJsonDocument doc{mess};
        client->sendTextMessage(doc.toJson());
    }

    {
        QJsonObject mess;
        mess["Message"] = "TriggerAdded";
        for(auto path : m_activeTimeNodes)
        {
            mess["Path"] = toJsonObject(path);
            QJsonDocument doc{mess};
            auto json = doc.toJson();
            client->sendTextMessage(json);
        }
    }

    m_clients.push_back(client);
}


void Receiver::processTextMessage(const QString& message)
{
    processBinaryMessage(message.toLatin1());
}


void Receiver::processBinaryMessage(QByteArray message)
{
    QJsonParseError error;
    auto doc = QJsonDocument::fromJson(std::move(message), &error);
    if(error.error)
        return;

    auto obj = doc.object();
    auto it = obj.find("Message");
    if(it == obj.end())
        return;

    auto mess = it->toString();
    auto answer_it = m_answers.find(mess);
    if(answer_it == m_answers.end())
        return;

    answer_it->second(obj);
}


void Receiver::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    if (pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}

}
