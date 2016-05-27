#pragma once
#include <iscore/plugins/settingsdelegate/SettingsDelegateFactoryInterface.hpp>

namespace RemoteControl
{
namespace Settings
{

class Factory :
        public iscore::SettingsDelegateFactory
{
        ISCORE_CONCRETE_FACTORY_DECL("56ec9b15-2d32-48d9-bab3-b44cf7942c7f")

        iscore::SettingsDelegateViewInterface *makeView() override;
        iscore::SettingsDelegatePresenterInterface* makePresenter_impl(
                iscore::SettingsDelegateModelInterface& m,
                iscore::SettingsDelegateViewInterface& v,
                QObject* parent) override;
        iscore::SettingsDelegateModelInterface *makeModel() override;
};

}
}
