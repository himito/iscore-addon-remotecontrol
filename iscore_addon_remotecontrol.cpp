#include "iscore_addon_remotecontrol.hpp"
#include <iscore/plugins/customfactory/FactorySetup.hpp>
iscore_addon_remotecontrol::iscore_addon_remotecontrol() :
    QObject {}
{
}

iscore_addon_remotecontrol::~iscore_addon_remotecontrol()
{

}

std::vector<std::unique_ptr<iscore::FactoryInterfaceBase>> iscore_addon_remotecontrol::factories(
        const iscore::ApplicationContext& ctx,
        const iscore::AbstractFactoryKey& key) const
{
    return instantiate_factories<
            iscore::ApplicationContext,
    TL<>>(ctx, key);
}

iscore::Version iscore_addon_remotecontrol::version() const
{
    return iscore::Version{1};
}

UuidKey<iscore::Plugin> iscore_addon_remotecontrol::key() const
{
    return "ecffb9d5-3d67-4b89-a64f-341b68cd9603";
}

