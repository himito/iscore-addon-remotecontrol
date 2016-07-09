#include "Loop.hpp"
#include <Scenario/Process/Algorithms/Accessors.hpp>
namespace RemoteControl
{

Loop::Loop(
        const Id<iscore::Component>& id,
        ::Loop::ProcessModel& scenario,
        Loop::system_t& doc,
        QObject* parent_obj):
    ProcessComponent{scenario, id, "LoopComponent", parent_obj},
    m_hm{*this, scenario, doc, this}
{
}

template<>
Constraint* Loop::make<Constraint, Scenario::ConstraintModel>(
        const Id<iscore::Component>& id,
        Scenario::ConstraintModel& elt,
        Loop::system_t& doc,
        QObject* parent)
{
    return new Constraint{id, elt, doc, parent};
}

template<>
Event* Loop::make<Event, Scenario::EventModel>(
        const Id<iscore::Component>& id,
        Scenario::EventModel& elt,
        Loop::system_t& doc,
        QObject* parent)
{
    return new Event{id, elt, doc, parent};
}

template<>
TimeNode* Loop::make<TimeNode, Scenario::TimeNodeModel>(
        const Id<iscore::Component>& id,
        Scenario::TimeNodeModel& elt,
        Loop::system_t& doc,
        QObject* parent)
{
    return new TimeNode{id, elt, doc, parent};
}

template<>
State* Loop::make<State, Scenario::StateModel>(
        const Id<iscore::Component>& id,
        Scenario::StateModel& elt,
        Loop::system_t& doc,
        QObject* parent)
{
    return new State{id, elt, doc, parent};
}

void Loop::removing(const Scenario::ConstraintModel& elt, const Constraint& comp)
{
}

void Loop::removing(const Scenario::EventModel& elt, const Event& comp)
{
}

void Loop::removing(const Scenario::TimeNodeModel& elt, const TimeNode& comp)
{
}

void Loop::removing(const Scenario::StateModel& elt, const State& comp)
{
}

}
