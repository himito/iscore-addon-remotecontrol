#include "Constraint.hpp"
namespace RemoteControl
{

const iscore::Component::Key&ConstraintComponent::key() const
{
    static const Key k{"b079041c-f11f-49b1-a88f-b2bc070affb1"};
    return k;
}


ConstraintComponent::ConstraintComponent(
        const Id<iscore::Component>& id,
        Scenario::ConstraintModel& constraint,
        const ConstraintComponent::system_t& doc,
        const iscore::DocumentContext& ctx,
        QObject* parent_comp):
    Component{id, "ConstraintComponent", parent_comp},
    m_baseComponent{*this, constraint, doc, ctx, this}
{
}

ConstraintComponent::~ConstraintComponent()
{
}

ProcessComponent*ConstraintComponent::make_processComponent(
        const Id<iscore::Component>& id,
        ProcessComponentFactory& factory,
        Process::ProcessModel& process,
        const DocumentPlugin& system,
        const iscore::DocumentContext& ctx,
        QObject* parent_component)
{
    return factory.make(id, process, system, ctx, parent_component);
}


void ConstraintComponent::removing(
        const Process::ProcessModel& cst,
        const ProcessComponent& comp)
{
}


}
