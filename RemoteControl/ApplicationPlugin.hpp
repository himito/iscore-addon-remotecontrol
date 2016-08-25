#pragma once
#include <iscore/plugins/application/GUIApplicationContextPlugin.hpp>

namespace RemoteControl
{
class ApplicationPlugin final :
        public iscore::GUIApplicationContextPlugin
{
    public:
        ApplicationPlugin(const iscore::GUIApplicationContext& app);

    protected:
        void on_createdDocument(iscore::Document& doc) override;
};
}
