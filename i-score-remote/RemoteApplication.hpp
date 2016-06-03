#pragma once
#include <QQmlApplicationEngine>
#include <QAbstractListModel>
#include <QtWebSockets/QtWebSockets>
#include <functional>

class QApplication;

struct TimeNodeInfo
{
        QJsonValue path;
        QString prettyName;
        friend bool operator==(const TimeNodeInfo& tn, const QJsonValue& rhs)
        { return tn.path == rhs; }
        friend bool operator!=(const TimeNodeInfo& tn, const QJsonValue& rhs)
        { return tn.path != rhs; }
};

class TriggerList : public QAbstractListModel
{
    public:
        template<typename Fun>
        void apply(Fun f)
        {
            beginResetModel();
            f();
            endResetModel();
        }

        int rowCount(const QModelIndex& ) const override
        {
            return timeNodes.size();
        }

        QVariant data(const QModelIndex& index, int ) const override
        {
            if(index.row() >= timeNodes.size())
                return {};

            return timeNodes[index.row()].prettyName;
        }

        QHash<int, QByteArray> roleNames() const override
        {
            QHash<int, QByteArray> hash;
            hash.insert(Qt::DisplayRole, "name");
            return hash;
        }
        std::vector<TimeNodeInfo> timeNodes;
};

struct WebSocketHandler : public QObject
{
        Q_OBJECT

    public:
        TriggerList m_activeTimeNodes;
    private:
        QWebSocket m_server;
        std::map<QString, std::function<void(const QJsonObject&)>> m_answers;

    public:
        WebSocketHandler()
        {
            m_answers.insert(std::make_pair("TriggerAdded", [this] (const QJsonObject& obj)
            {
                qDebug() << obj;
                auto json_it = obj.find("Path");
                if(json_it == obj.end())
                    return;

                auto it = std::find(
                            m_activeTimeNodes.timeNodes.begin(),
                            m_activeTimeNodes.timeNodes.end(),
                            *json_it);
                if(it == m_activeTimeNodes.timeNodes.end())
                {
                    m_activeTimeNodes.apply([=] () {
                        m_activeTimeNodes.timeNodes.emplace_back(TimeNodeInfo{*json_it, obj["Name"].toString()});
                    });
                }
            }));

            m_answers.insert(std::make_pair("TriggerRemoved", [this] (const QJsonObject& obj)
            {
                qDebug() << obj;
                auto json_it = obj.find("Path");
                if(json_it == obj.end())
                    return;

                auto it = std::find(
                            m_activeTimeNodes.timeNodes.begin(),
                            m_activeTimeNodes.timeNodes.end(),
                            *json_it);
                if(it != m_activeTimeNodes.timeNodes.end())
                {
                    m_activeTimeNodes.apply([=] () { m_activeTimeNodes.timeNodes.erase(it); });
                }
            }));


            connect(&m_server, &QWebSocket::textMessageReceived,
                    this, &WebSocketHandler::processTextMessage);
            connect(&m_server, &QWebSocket::binaryMessageReceived,
                    this, &WebSocketHandler::processBinaryMessage);
            connect(&m_server, &QWebSocket::connected,
                    this, [] { qDebug("yolooo"); });
            connect(&m_server, static_cast<void(QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error),
                    this , [=](QAbstractSocket::SocketError) { qDebug() << m_server.errorString(); });

            m_server.open(QUrl("ws://147.210.128.72:10212"));
        }

        ~WebSocketHandler()
        {
            m_server.close();
        }

        void processTextMessage(const QString& message)
        {
            processBinaryMessage(message.toLatin1());
        }


        void processBinaryMessage(QByteArray message)
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


    public slots:
        void on_rowPressed(int i)
        {
            if(i >= m_activeTimeNodes.timeNodes.size())
                return;

            auto tn = m_activeTimeNodes.timeNodes[i];

            QJsonObject mess;
            mess["Message"] = "Trigger";
            mess["Path"] = tn.path;
            QJsonDocument doc{mess};
            auto json = doc.toJson();

            m_server.sendTextMessage(json);
        }

        void on_play()
        {
            QJsonObject mess;
            mess["Message"] = "Play";
            m_server.sendTextMessage(QJsonDocument{mess}.toJson());
        }

        void on_pause()
        {
            QJsonObject mess;
            mess["Message"] = "Pause";
            m_server.sendTextMessage(QJsonDocument{mess}.toJson());
        }

        void on_stop()
        {
            QJsonObject mess;
            mess["Message"] = "Stop";
            m_server.sendTextMessage(QJsonDocument{mess}.toJson());
        }

        void on_addressChanged(QString addr)
        {
            m_server.close();

            m_activeTimeNodes.apply([this] () { m_activeTimeNodes.timeNodes.clear(); });

            m_server.open(QUrl{addr});
        }
};

class RemoteApplication final : QObject
{
    public:
        RemoteApplication(int& argc, char** argv);
        ~RemoteApplication();

        int exec();

        // Base stuff.
        QApplication* m_app;

        QQmlApplicationEngine engine;
        WebSocketHandler m_triggers;
};
