#include "iscore_addon_remotecontrol.hpp"
#include <iscore/plugins/customfactory/FactorySetup.hpp>
#include <RemoteControl/ApplicationPlugin.hpp>
#include <RemoteControl/Settings/Factory.hpp>

#include <RemoteControl/Scenario/Scenario.hpp>
#include <RemoteControl/Scenario/Loop.hpp>

#include <Scenario/iscore_plugin_scenario.hpp>
#include <iscore_plugin_deviceexplorer.hpp>

iscore_addon_remotecontrol::iscore_addon_remotecontrol() :
    QObject {}
{
}

iscore_addon_remotecontrol::~iscore_addon_remotecontrol()
{

}

iscore::GUIApplicationPlugin*iscore_addon_remotecontrol::make_guiApplicationPlugin(
        const iscore::GUIApplicationContext& app)
{
    return new RemoteControl::ApplicationPlugin{app};
}

std::vector<std::unique_ptr<iscore::InterfaceListBase> > iscore_addon_remotecontrol::factoryFamilies()
{
    return make_ptr_vector<iscore::InterfaceListBase,
            RemoteControl::ProcessComponentFactoryList
            >();
}

std::vector<std::unique_ptr<iscore::InterfaceBase>> iscore_addon_remotecontrol::factories(
        const iscore::ApplicationContext& ctx,
        const iscore::InterfaceKey& key) const
{
    return instantiate_factories<
            iscore::ApplicationContext,
            FW<iscore::SettingsDelegateFactory,
            RemoteControl::Settings::Factory>,
            FW<RemoteControl::ProcessComponentFactory,
                RemoteControl::ScenarioComponentFactory,
                RemoteControl::LoopComponentFactory>
            >(ctx, key);
}

auto iscore_addon_remotecontrol::required() const
  -> std::vector<iscore::PluginKey>
{
    return {
      iscore_plugin_scenario::static_key(),
      iscore_plugin_deviceexplorer::static_key()
    };
}
