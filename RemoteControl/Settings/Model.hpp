#pragma once
#include <iscore/plugins/settingsdelegate/SettingsDelegateModel.hpp>
#include <iscore_addon_remotecontrol_export.h>

namespace RemoteControl
{
namespace Settings
{
class ISCORE_ADDON_REMOTECONTROL_EXPORT Model :
        public iscore::SettingsDelegateModel
{
        Q_OBJECT

    Q_PROPERTY(bool Enabled READ getEnabled WRITE setEnabled NOTIFY EnabledChanged FINAL)

        bool m_Enabled = false;
    public:
        Model(QSettings& set, const iscore::ApplicationContext& ctx);

        ISCORE_SETTINGS_PARAMETER_HPP(bool, Enabled)
};

ISCORE_SETTINGS_PARAMETER(Model, Enabled)

}
}
