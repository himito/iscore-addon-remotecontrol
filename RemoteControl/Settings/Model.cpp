#include "Model.hpp"
#include <QSettings>

namespace RemoteControl
{
namespace Settings
{

const QString Keys::enabled = QStringLiteral("RemoteControl/Enabled");

Model::Model()
{
    QSettings s;

    if(!s.contains(Keys::enabled))
    {
        setFirstTimeSettings();
    }

    m_enabled = s.value(Keys::enabled).toBool();
}

bool Model::getEnabled() const
{
  return m_enabled;
}

void Model::setEnabled(bool enabled)
{
  if (m_enabled == enabled)
    return;

  m_enabled = enabled;
  QSettings s;
  s.setValue(Keys::enabled, m_enabled);
  emit EnabledChanged(enabled);
}

void Model::setFirstTimeSettings()
{
    m_enabled = true;

    QSettings s;
    s.setValue(Keys::enabled, m_enabled);
}

}
}
