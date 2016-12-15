#include "iscore_addon_remotecontrol.hpp"
#include <iscore/plugins/customfactory/FactorySetup.hpp>
#include <RemoteControl/ApplicationPlugin.hpp>
#include <RemoteControl/Settings/Factory.hpp>

#include <RemoteControl/Scenario/Scenario.hpp>
#include <RemoteControl/Scenario/Loop.hpp>
iscore_addon_remotecontrol::iscore_addon_remotecontrol() :
    QObject {}
{
}

iscore_addon_remotecontrol::~iscore_addon_remotecontrol()
{

}

iscore::GUIApplicationContextPlugin*iscore_addon_remotecontrol::make_applicationPlugin(
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

iscore::Version iscore_addon_remotecontrol::version() const
{
    return iscore::Version{1};
}

QStringList iscore_addon_remotecontrol::required() const
{
    return {"Scenario", "DeviceExplorer"};
}

UuidKey<iscore::Plugin> iscore_addon_remotecontrol::key() const
{
    return_uuid("ecffb9d5-3d67-4b89-a64f-341b68cd9603");
}

