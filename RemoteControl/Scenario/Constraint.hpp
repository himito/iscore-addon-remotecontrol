#pragma once
#include <RemoteControl/Scenario/Process.hpp>
#include <RemoteControl/DocumentPlugin.hpp>
#include <Scenario/Document/Components/ConstraintComponent.hpp>

namespace RemoteControl
{
namespace Mix
{
class ProcessModel;
}
class Constraint final :
        public iscore::Component
{
    public:
        using system_t = RemoteControl::DocumentPlugin;
        using process_component_t = RemoteControl::ProcessComponent;
        using process_component_factory_t = RemoteControl::ProcessComponentFactory;
        using process_component_factory_list_t = RemoteControl::ProcessComponentFactoryList;

        using parent_t = ::ConstraintComponentHierarchyManager<
            Constraint,
            system_t,
            process_component_t,
            process_component_factory_list_t
        >;

        const Key& key() const override;

        Constraint(
                const Id<Component>& id,
                Scenario::ConstraintModel& constraint,
                system_t& doc,
                QObject* parent_comp);
        ~Constraint();

        ProcessComponent* make_processComponent(
                const Id<Component> & id,
                ProcessComponentFactory& factory,
                Process::ProcessModel &process,
                DocumentPlugin &system,
                QObject *parent_component);

        void removing(const Process::ProcessModel& cst, const ProcessComponent& comp);

        const auto& processes() const
        { return m_baseComponent.processes(); }

    private:
        Mix::ProcessModel* findMix() const;

        parent_t m_baseComponent;
};



}
