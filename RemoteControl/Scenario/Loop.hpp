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
        COMPONENT_METADATA("67fb5b6b-12fb-40a2-8108-429b89251a1b")

    public:
       using system_t = RemoteControl::DocumentPlugin;
       system_t& system;
       LoopBase(
               const Id<iscore::Component>& id,
               ::Loop::ProcessModel& scenario,
               system_t& doc,
               QObject* parent_obj);

       template<typename Component_T, typename Element>
       Component_T* make(
               const Id<iscore::Component>& id,
               Element& elt,
               QObject* parent);

       template<typename... Args>
       void removing(Args&&...) {}
};

using Loop =
   HierarchicalBaseScenario<
       LoopBase,
       LoopBase::system_t,
       ::Loop::ProcessModel,
       Constraint,
       Event,
       TimeNode,
       State
>;
}
