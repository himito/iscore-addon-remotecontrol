#pragma once
#include <iscore/plugins/application/GUIApplicationPlugin.hpp>

namespace RemoteControl
{
class ApplicationPlugin final :
        public iscore::GUIApplicationPlugin
{
    public:
        ApplicationPlugin(const iscore::GUIApplicationContext& app);

    protected:
        void on_createdDocument(iscore::Document& doc) override;
};
}
