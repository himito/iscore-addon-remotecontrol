#include "Loop.hpp"
#include <Scenario/Process/Algorithms/Accessors.hpp>
namespace RemoteControl
{

LoopBase::LoopBase(
        const Id<iscore::Component>& id,
        ::Loop::ProcessModel& scenario,
        LoopBase::system_t& doc,
        QObject* parent_obj):
    ProcessComponent_T{scenario, id, "LoopComponent", parent_obj},
    system{doc}
{
}

template<>
Constraint* LoopBase::make<Constraint, Scenario::ConstraintModel>(
        const Id<iscore::Component>& id,
        Scenario::ConstraintModel& elt,
        QObject* parent)
{
    return new Constraint{id, elt, system, parent};
}

template<>
Event* LoopBase::make<Event, Scenario::EventModel>(
        const Id<iscore::Component>& id,
        Scenario::EventModel& elt,
        QObject* parent)
{
    return new Event{id, elt, system, parent};
}

template<>
TimeNode* LoopBase::make<TimeNode, Scenario::TimeNodeModel>(
        const Id<iscore::Component>& id,
        Scenario::TimeNodeModel& elt,
        QObject* parent)
{
    return new TimeNode{id, elt, system, parent};
}

template<>
State* LoopBase::make<State, Scenario::StateModel>(
        const Id<iscore::Component>& id,
        Scenario::StateModel& elt,
        QObject* parent)
{
    return new State{id, elt, system, parent};
}

}
