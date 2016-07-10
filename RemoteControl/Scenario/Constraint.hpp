#pragma once
#include <RemoteControl/Scenario/Process.hpp>
#include <RemoteControl/DocumentPlugin.hpp>
#include <Scenario/Document/Components/ConstraintComponent.hpp>

namespace RemoteControl
{
class ConstraintBase :
        public Scenario::GenericConstraintComponent<RemoteControl::DocumentPlugin>
{
        COMPONENT_METADATA("b079041c-f11f-49b1-a88f-b2bc070affb1")
    public:
        using parent_t = Scenario::GenericConstraintComponent<RemoteControl::DocumentPlugin>;
        using DocumentPlugin = RemoteControl::DocumentPlugin;
        using process_component_t = RemoteControl::ProcessComponent;
        using process_component_factory_t = RemoteControl::ProcessComponentFactory;
        using process_component_factory_list_t = RemoteControl::ProcessComponentFactoryList;

        ConstraintBase(
                const Id<iscore::Component>& id,
                Scenario::ConstraintModel& constraint,
                DocumentPlugin& doc,
                QObject* parent_comp);

        ProcessComponent* make_processComponent(
                const Id<iscore::Component> & id,
                ProcessComponentFactory& factory,
                Process::ProcessModel &process);

        void removing(const Process::ProcessModel& cst, const ProcessComponent& comp);
};

class Constraint final : public ConstraintComponentHierarchyManager<
    ConstraintBase,
    ConstraintBase::process_component_t,
    ConstraintBase::process_component_factory_list_t
>
{
    public:
        using hierarchy_t::ConstraintComponentHierarchyManager;

};
}
