#include "Presenter.hpp"
#include "Model.hpp"
#include "View.hpp"
#include <iscore/command/SerializableCommand.hpp>
#include <iscore/command/Dispatchers/ICommandDispatcher.hpp>
#include <QApplication>
#include <QStyle>
#include <iscore/command/SettingsCommand.hpp>

namespace RemoteControl
{
namespace Settings
{
Presenter::Presenter(
        Model& m,
        View& v,
        QObject *parent):
    iscore::SettingsDelegatePresenter{m, v, parent}
{
    {
        // view -> model
        con(v, &View::enabledChanged,
            this, [&] (auto val) {
            if(val != m.getEnabled())
            {
                m_disp.submitCommand<SetModelEnabled>(this->model(this), val);
            }
        });

        // model -> view
        con(m, &Model::EnabledChanged, &v, &View::setEnabled);

        // initial value
        v.setEnabled(m.getEnabled());
    }

}

QString Presenter::settingsName()
{
    return tr("Remote Control");
}

QIcon Presenter::settingsIcon()
{
    return QApplication::style()->standardIcon(QStyle::SP_CommandLink);
}

}
}
