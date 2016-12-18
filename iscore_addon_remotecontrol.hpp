#pragma once
#include <iscore/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/FactoryFamily_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/GUIApplicationContextPlugin_QtInterface.hpp>
#include <iscore/application/ApplicationContext.hpp>
#include <iscore/plugins/customfactory/FactoryInterface.hpp>

#include <QObject>
#include <utility>
#include <vector>

class iscore_addon_remotecontrol final :
        public QObject,
        public iscore::Plugin_QtInterface,
        public iscore::FactoryList_QtInterface,
        public iscore::FactoryInterface_QtInterface,
        public iscore::GUIApplicationContextPlugin_QtInterface
{
        Q_OBJECT
        Q_PLUGIN_METADATA(IID FactoryInterface_QtInterface_iid)
        Q_INTERFACES(
                iscore::Plugin_QtInterface
                iscore::FactoryList_QtInterface
                iscore::FactoryInterface_QtInterface
                iscore::GUIApplicationContextPlugin_QtInterface
                )
        ISCORE_PLUGIN_METADATA(1, "ecffb9d5-3d67-4b89-a64f-341b68cd9603")
    public:
        iscore_addon_remotecontrol();
        virtual ~iscore_addon_remotecontrol();

    private:
        iscore::GUIApplicationContextPlugin* make_applicationPlugin(
                const iscore::GUIApplicationContext& app) override;


        std::vector<std::unique_ptr<iscore::InterfaceListBase>> factoryFamilies() override;


        std::vector<std::unique_ptr<iscore::InterfaceBase>> factories(
                const iscore::ApplicationContext& ctx,
                const iscore::InterfaceKey& factoryName) const override;

        std::vector<iscore::PluginKey> required() const override;
};
