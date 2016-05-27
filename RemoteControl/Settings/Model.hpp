#pragma once
#include <iscore/plugins/settingsdelegate/SettingsDelegateModelInterface.hpp>
#include <iscore_addon_remotecontrol_export.h>

namespace RemoteControl
{
namespace Settings
{
struct Keys
{
        static const QString enabled;
};

class ISCORE_ADDON_REMOTECONTROL_EXPORT Model :
        public iscore::SettingsDelegateModelInterface
{
        Q_OBJECT

    Q_PROPERTY(bool enabled READ getEnabled WRITE setEnabled NOTIFY EnabledChanged)
    public:
        Model();

        bool getEnabled() const;
        void setEnabled(bool enabled);

  signals:
        void EnabledChanged(bool enabled);

  private:
        void setFirstTimeSettings() override;
        bool m_enabled = false;
};

ISCORE_SETTINGS_PARAMETER(Model, Enabled)

}
}
