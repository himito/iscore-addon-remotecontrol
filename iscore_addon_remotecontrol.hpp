#pragma once
#include <iscore/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/GUIApplicationContextPlugin_QtInterface.hpp>
#include <iscore/application/ApplicationContext.hpp>
#include <iscore/plugins/customfactory/FactoryInterface.hpp>

#include <QObject>
#include <utility>
#include <vector>

class iscore_addon_remotecontrol final :
        public QObject,
        public iscore::Plugin_QtInterface,
        public iscore::FactoryInterface_QtInterface
{
        Q_OBJECT
        Q_PLUGIN_METADATA(IID FactoryInterface_QtInterface_iid)
        Q_INTERFACES(
                iscore::Plugin_QtInterface
                iscore::FactoryInterface_QtInterface
                )

    public:
        iscore_addon_remotecontrol();
        virtual ~iscore_addon_remotecontrol();

    private:
        // Process & inspector
        std::vector<std::unique_ptr<iscore::FactoryInterfaceBase>> factories(
                const iscore::ApplicationContext& ctx,
                const iscore::AbstractFactoryKey& factoryName) const override;

        iscore::Version version() const override;
        UuidKey<iscore::Plugin> key() const override;
};
