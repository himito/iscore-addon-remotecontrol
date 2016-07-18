#include "Constraint.hpp"
namespace RemoteControl
{
ConstraintBase::ConstraintBase(
        const Id<iscore::Component>& id,
        Scenario::ConstraintModel& constraint,
        DocumentPlugin& doc,
        QObject* parent_comp):
    parent_t{constraint, doc, id, "ConstraintComponent", parent_comp}
{
}

ProcessComponent*ConstraintBase::make(
        const Id<iscore::Component>& id,
        ProcessComponentFactory& factory,
        Process::ProcessModel& process)
{
    return factory.make(process, system(), id, this);
}


void ConstraintBase::removing(
        const Process::ProcessModel& cst,
        const ProcessComponent& comp)
{
}


}
