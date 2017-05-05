#include "Process.hpp"
#include <Process/Process.hpp>

RemoteControl::ProcessComponent::ProcessComponent(
        Process::ProcessModel& process,
        DocumentPlugin& doc,
        const Id<iscore::Component>& id,
        const QString& name,
        QObject* parent):
    Scenario::GenericProcessComponent<DocumentPlugin>{process, doc, id, name, parent}
{
}

RemoteControl::ProcessComponent::~ProcessComponent()
{

}

RemoteControl::ProcessComponentFactory::~ProcessComponentFactory()
{

}
