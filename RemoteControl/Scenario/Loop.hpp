#pragma once
#include <RemoteControl/Scenario/Constraint.hpp>
#include <RemoteControl/Scenario/Event.hpp>
#include <RemoteControl/Scenario/TimeNode.hpp>
#include <RemoteControl/Scenario/State.hpp>
#include <Scenario/Document/Components/ScenarioComponent.hpp>
#include <Loop/LoopProcessModel.hpp>
#include <QMetaObject>
namespace RemoteControl
{
class LoopBase :
        public ProcessComponent_T<Loop::ProcessModel>
{
        COMMON_COMPONENT_METADATA("67fb5b6b-12fb-40a2-8108-429b89251a1b")

    public:
       LoopBase(
               ::Loop::ProcessModel& scenario,
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

using LoopComponent =
   HierarchicalBaseScenario<
       LoopBase,
       ::Loop::ProcessModel,
       Constraint,
       Event,
       TimeNode,
       State
>;

using LoopComponentFactory = ProcessComponentFactory_T<LoopComponent>;

}
