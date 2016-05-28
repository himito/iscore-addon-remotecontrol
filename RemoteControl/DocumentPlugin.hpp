#pragma once
#include <iscore/plugins/documentdelegate/plugin/DocumentDelegatePluginModel.hpp>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
template<typename T>
class TreeNode;
namespace Device
{
class DeviceExplorerNode;
using Node = TreeNode<DeviceExplorerNode>;
}
namespace Explorer
{
class DeviceDocumentPlugin;
}
namespace Scenario
{
class TimeNodeModel;
}
namespace RemoteControl
{
class Constraint;

struct Receiver : public QObject
{
    public:
        explicit Receiver(
                const iscore::DocumentContext& doc,
                quint16 port);

        ~Receiver();

        void registerTimeNode(Path<Scenario::TimeNodeModel> tn);

        void unregisterTimeNode(Path<Scenario::TimeNodeModel> tn);

    signals:
        void closed();

    public slots:
        void onNewConnection();

        void processTextMessage(const QString& message);

        void processBinaryMessage(QByteArray message);

        void socketDisconnected();


    private:
        QWebSocketServer m_server;
        QList<QWebSocket *> m_clients;

        Explorer::DeviceDocumentPlugin& m_dev;
        std::list<Path<Scenario::TimeNodeModel>> m_activeTimeNodes;

        std::map<QString, std::function<void(const QJsonObject&)>> m_answers;
};

class DocumentPlugin : public iscore::DocumentPlugin
{
    public:
        DocumentPlugin(
                const iscore::DocumentContext& doc,
                QObject* parent);

        ~DocumentPlugin();

        Receiver receiver;

    private:
        void create();
        void cleanup();

        Constraint* m_root{};
};
}
