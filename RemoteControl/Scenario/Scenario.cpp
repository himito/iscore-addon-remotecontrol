#include "Scenario.hpp"
#include <Scenario/Process/Algorithms/Accessors.hpp>
namespace RemoteControl
{

ScenarioComponent::ScenarioComponent(
        const Id<iscore::Component>& id,
        Scenario::ProcessModel& scenario,
        ScenarioComponent::system_t& doc,
        QObject* parent_obj):
    ProcessComponent{scenario, id, "ScenarioComponent", parent_obj},
    m_hm{*this, scenario, doc, this}
{
}

template<>
Constraint* ScenarioComponent::make<Constraint, Scenario::ConstraintModel>(
        const Id<iscore::Component>& id,
        Scenario::ConstraintModel& elt,
        ScenarioComponent::system_t& doc,
        QObject* parent)
{
    return new Constraint{id, elt, doc, parent};
}

template<>
Event* ScenarioComponent::make<Event, Scenario::EventModel>(
        const Id<iscore::Component>& id,
        Scenario::EventModel& elt,
        ScenarioComponent::system_t& doc,
        QObject* parent)
{
    return new Event{id, elt, doc, parent};
}

template<>
TimeNode* ScenarioComponent::make<TimeNode, Scenario::TimeNodeModel>(
        const Id<iscore::Component>& id,
        Scenario::TimeNodeModel& elt,
        ScenarioComponent::system_t& doc,
        QObject* parent)
{
    return new TimeNode{id, elt, doc, parent};
}

template<>
State* ScenarioComponent::make<State, Scenario::StateModel>(
        const Id<iscore::Component>& id,
        Scenario::StateModel& elt,
        ScenarioComponent::system_t& doc,
        QObject* parent)
{
    return new State{id, elt, doc, parent};
}

void ScenarioComponent::removing(const Scenario::ConstraintModel& elt, const Constraint& comp)
{
}

void ScenarioComponent::removing(const Scenario::EventModel& elt, const Event& comp)
{
}

void ScenarioComponent::removing(const Scenario::TimeNodeModel& elt, const TimeNode& comp)
{
}

void ScenarioComponent::removing(const Scenario::StateModel& elt, const State& comp)
{
}

}
