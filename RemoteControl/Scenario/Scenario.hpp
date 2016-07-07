#pragma once
#include <RemoteControl/Scenario/Constraint.hpp>
#include <RemoteControl/Scenario/Event.hpp>
#include <RemoteControl/Scenario/TimeNode.hpp>
#include <RemoteControl/Scenario/State.hpp>
#include <Scenario/Document/Components/ScenarioComponent.hpp>
#include <QMetaObject>
namespace RemoteControl
{
class ScenarioComponent final :
        public ProcessComponent
{
       COMPONENT_METADATA(RemoteControl::ScenarioComponent)

        using system_t = RemoteControl::DocumentPlugin;
        using hierarchy_t =
           ScenarioComponentHierarchyManager<
               ScenarioComponent,
               system_t,
               Scenario::ProcessModel,
               Constraint,
               Event,
               TimeNode,
               State
        >;

    public:
       ScenarioComponent(
               const Id<Component>& id,
               Scenario::ProcessModel& scenario,
               system_t& doc,
               const iscore::DocumentContext& ctx,
               QObject* parent_obj);



       const auto& constraints() const
       { return m_hm.constraints(); }

       template<typename Component_T, typename Element>
       Component_T* make(
               const Id<Component>& id,
               Element& elt,
               system_t& doc,
               const iscore::DocumentContext& ctx,
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
