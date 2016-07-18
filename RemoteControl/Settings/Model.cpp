#include "Model.hpp"
#include <QSettings>

namespace RemoteControl
{
namespace Settings
{

namespace Parameters
{
        const iscore::sp<ModelEnabledParameter> Enabled{
            QStringLiteral("RemoteControl/Enabled"),
                    false};

        static auto list() {
            return std::tie(Enabled);
        }
}

Model::Model(QSettings& set, const iscore::ApplicationContext& ctx)
{
    iscore::setupDefaultSettings(set, Parameters::list(), *this);
}

ISCORE_SETTINGS_PARAMETER_CPP(bool, Model, Enabled)
}
}
