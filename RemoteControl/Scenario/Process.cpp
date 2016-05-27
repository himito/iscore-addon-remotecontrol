#include "Process.hpp"
#include <Process/Process.hpp>

RemoteControl::ProcessComponent::ProcessComponent(
        Process::ProcessModel& process,
        const Id<iscore::Component>& id,
        const QString& name,
        QObject* parent):
    Component{id, name, parent},
    m_process{process}
{
}

RemoteControl::ProcessComponent::~ProcessComponent()
{

}

RemoteControl::ProcessComponentFactory::~ProcessComponentFactory()
{

}
