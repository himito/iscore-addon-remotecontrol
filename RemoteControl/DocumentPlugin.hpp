#pragma once
#include <iscore/plugins/documentdelegate/plugin/DocumentPlugin.hpp>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <State/Message.hpp>
#include <nano_observer.hpp>
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

struct WSClient
{
  QWebSocket* socket{};
  friend bool operator==(const WSClient& lhs, const WSClient& rhs)
  { return lhs.socket == rhs.socket; }
};

struct Receiver : public QObject, public Nano::Observer
{
    public:
        explicit Receiver(
                const iscore::DocumentContext& doc,
                quint16 port);

        ~Receiver();

        void registerTimeNode(Path<Scenario::TimeNodeModel> tn);

        void unregisterTimeNode(Path<Scenario::TimeNodeModel> tn);

        void onNewConnection();

        void processTextMessage(const QString& message, const WSClient& w);

        void processBinaryMessage(QByteArray message, const WSClient& w);

        void socketDisconnected();


    private:
        void on_valueUpdated(
            const ::State::Address& addr, const ossia::value& v);

        QWebSocketServer m_server;
        QList<WSClient> m_clients;

        Explorer::DeviceDocumentPlugin& m_dev;
        std::list<Path<Scenario::TimeNodeModel>> m_activeTimeNodes;

        std::map<QString, std::function<void(const QJsonObject&, const WSClient&)>> m_answers;
        iscore::hash_map<::State::Address, WSClient> m_listenedAddresses;
};

class DocumentPlugin : public iscore::DocumentPlugin
{
    public:
        DocumentPlugin(
                const iscore::DocumentContext& doc,
                Id<iscore::DocumentPlugin> id,
                QObject* parent);

        ~DocumentPlugin();

        void on_documentClosing() override;
        Receiver receiver;

    private:
        void create();
        void cleanup();

        Constraint* m_root{};
};
}
