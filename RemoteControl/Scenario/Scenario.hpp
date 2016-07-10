#pragma once
#include <RemoteControl/Scenario/Constraint.hpp>
#include <RemoteControl/Scenario/Event.hpp>
#include <RemoteControl/Scenario/TimeNode.hpp>
#include <RemoteControl/Scenario/State.hpp>
#include <Scenario/Document/Components/ScenarioComponent.hpp>
#include <QMetaObject>

namespace RemoteControl
{
class ScenarioBase :
        public ProcessComponent_T<Scenario::ProcessModel>
{
        COMPONENT_METADATA("fce752e0-e37a-4b71-bc2a-65366ec87152")

    public:
       ScenarioBase(
               Scenario::ProcessModel& scenario,
               DocumentPlugin& doc,
                const Id<iscore::Component>& id,
               QObject* parent_obj);

       template<typename Component_T, typename Element>
       Component_T* make(
               const Id<iscore::Component>& id,
               Element& elt)
       {
           return new Component_T{id, elt, system(), this};
       }

       template<typename... Args>
       void removing(Args&&...) { }
};

using ScenarioComponent = HierarchicalScenarioComponent<
    ScenarioBase,
    Scenario::ProcessModel,
    Constraint,
    Event,
    TimeNode,
    State>;


using ScenarioComponentFactory = ProcessComponentFactory_T<ScenarioComponent>;
}
