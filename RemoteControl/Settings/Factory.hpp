#pragma once
#include <iscore/plugins/settingsdelegate/SettingsDelegateFactory.hpp>

#include <RemoteControl/Settings/Model.hpp>
#include <RemoteControl/Settings/Presenter.hpp>
#include <RemoteControl/Settings/View.hpp>

namespace RemoteControl
{
namespace Settings
{
ISCORE_DECLARE_SETTINGS_FACTORY(Factory, Model, Presenter, View, "56ec9b15-2d32-48d9-bab3-b44cf7942c7f")
}
}
