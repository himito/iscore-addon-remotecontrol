#pragma once
#include <iscore/plugins/application/GUIApplicationContextPlugin.hpp>

namespace RemoteControl
{
class ApplicationPlugin final :
        public iscore::GUIApplicationContextPlugin
{
    public:
        ApplicationPlugin(const iscore::ApplicationContext& app);

    protected:
        void on_newDocument(iscore::Document* doc) override;
};
}
