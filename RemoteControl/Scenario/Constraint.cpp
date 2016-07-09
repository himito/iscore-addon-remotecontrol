#include "Constraint.hpp"
namespace RemoteControl
{

const iscore::Component::Key&Constraint::key() const
{
    static const Key k{"b079041c-f11f-49b1-a88f-b2bc070affb1"};
    return k;
}


Constraint::Constraint(
        const Id<iscore::Component>& id,
        Scenario::ConstraintModel& constraint,
        Constraint::system_t& doc,
        QObject* parent_comp):
    Component{id, "ConstraintComponent", parent_comp},
    m_baseComponent{*this, constraint, doc, this}
{
}

Constraint::~Constraint()
{
}

ProcessComponent*Constraint::make_processComponent(
        const Id<iscore::Component>& id,
        ProcessComponentFactory& factory,
        Process::ProcessModel& process,
        DocumentPlugin& system,
        QObject* parent_component)
{
    return factory.make(id, process, system, parent_component);
}


void Constraint::removing(
        const Process::ProcessModel& cst,
        const ProcessComponent& comp)
{
}


}
