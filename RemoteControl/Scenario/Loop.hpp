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
class Loop final :
        public ProcessComponent
{
        COMPONENT_METADATA("67fb5b6b-12fb-40a2-8108-429b89251a1b")

        using system_t = RemoteControl::DocumentPlugin;
        using hierarchy_t =
           BaseScenarioComponentHierarchyManager<
               Loop,
               system_t,
               ::Loop::ProcessModel,
               Constraint,
               Event,
               TimeNode,
               State
        >;

    public:
       Loop(
               const Id<Component>& id,
               ::Loop::ProcessModel& scenario,
               system_t& doc,
               QObject* parent_obj);

       const auto& constraints() const
       { return m_hm.constraints(); }

       template<typename Component_T, typename Element>
       Component_T* make(
               const Id<Component>& id,
               Element& elt,
               system_t& doc,
               QObject* parent);

        void removing(
                const Scenario::ConstraintModel& elt,
                const Constraint& comp);

        void removing(
                const Scenario::EventModel& elt,
                const Event& comp);

        void removing(
                const Scenario::TimeNodeModel& elt,
                const TimeNode& comp);

        void removing(
                const Scenario::StateModel& elt,
                const State& comp);

    private:
        hierarchy_t m_hm;

};

}
