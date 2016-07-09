#include "Scenario.hpp"
#include <Scenario/Process/Algorithms/Accessors.hpp>
namespace RemoteControl
{

ScenarioComponentBase::ScenarioComponentBase(
        const Id<iscore::Component>& id,
        Scenario::ProcessModel& scenario,
        ScenarioComponentBase::system_t& doc,
        QObject* parent_obj):
    ProcessComponent{scenario, id, "ScenarioComponent", parent_obj}
{
}

template<>
Constraint* ScenarioComponentBase::make<Constraint, Scenario::ConstraintModel>(
        const Id<iscore::Component>& id,
        Scenario::ConstraintModel& elt,
        ScenarioComponentBase::system_t& doc,
        QObject* parent)
{
    return new Constraint{id, elt, doc, parent};
}

template<>
Event* ScenarioComponentBase::make<Event, Scenario::EventModel>(
        const Id<iscore::Component>& id,
        Scenario::EventModel& elt,
        ScenarioComponentBase::system_t& doc,
        QObject* parent)
{
    return new Event{id, elt, doc, parent};
}

template<>
TimeNode* ScenarioComponentBase::make<TimeNode, Scenario::TimeNodeModel>(
        const Id<iscore::Component>& id,
        Scenario::TimeNodeModel& elt,
        ScenarioComponentBase::system_t& doc,
        QObject* parent)
{
    return new TimeNode{id, elt, doc, parent};
}

template<>
State* ScenarioComponentBase::make<State, Scenario::StateModel>(
        const Id<iscore::Component>& id,
        Scenario::StateModel& elt,
        ScenarioComponentBase::system_t& doc,
        QObject* parent)
{
    return new State{id, elt, doc, parent};
}

}
