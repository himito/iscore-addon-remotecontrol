#include "ScenarioFactory.hpp"
#include "Scenario.hpp"

namespace RemoteControl
{
bool ScenarioFactory::matches(
        Process::ProcessModel& p,
        const DocumentPlugin&) const
{
    return dynamic_cast<Scenario::ProcessModel*>(&p);
}

ProcessComponent*
ScenarioFactory::make(
        const Id<iscore::Component>& id,
        Process::ProcessModel& proc,
        DocumentPlugin& doc,
        QObject* paren_objt) const
{
    return new ScenarioComponent(id, static_cast<Scenario::ProcessModel&>(proc), doc, paren_objt);
}

}
