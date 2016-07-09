#pragma once
#include <RemoteControl/Scenario/Constraint.hpp>
#include <RemoteControl/Scenario/Event.hpp>
#include <RemoteControl/Scenario/TimeNode.hpp>
#include <RemoteControl/Scenario/State.hpp>
#include <Scenario/Document/Components/ScenarioComponent.hpp>
#include <QMetaObject>
namespace RemoteControl
{
class ScenarioComponentBase final :
        public ProcessComponent
{
        COMPONENT_METADATA("fce752e0-e37a-4b71-bc2a-65366ec87152")

    public:
            using system_t = RemoteControl::DocumentPlugin;
       ScenarioComponentBase(
               const Id<Component>& id,
               Scenario::ProcessModel& scenario,
               system_t& doc,
               QObject* parent_obj);

       template<typename Component_T, typename Element>
       Component_T* make(
               const Id<Component>& id,
               Element& elt,
               system_t& doc,
               QObject* parent);

       template<typename... Args>
       void removing(Args&&...) { }
};

using ScenarioComponent = HierarchicalScenarioComponent<
    ScenarioComponentBase,
    ScenarioComponentBase::system_t,
    Scenario::ProcessModel,
    Constraint,
    Event,
    TimeNode,
    State>;
}
