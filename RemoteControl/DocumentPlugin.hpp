#pragma once
#include <iscore/plugins/documentdelegate/plugin/DocumentDelegatePluginModel.hpp>

namespace RemoteControl
{
class ConstraintComponent;
class DocumentPlugin : public iscore::DocumentPlugin
{
    public:
        DocumentPlugin(
                const iscore::DocumentContext& doc,
                QObject* parent);

        ~DocumentPlugin();

    private:
        void create();
        void cleanup();

        ConstraintComponent* m_root{};
};
}
