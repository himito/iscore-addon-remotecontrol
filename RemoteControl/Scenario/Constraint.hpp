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
class ConstraintComponent final :
        public iscore::Component
{
    public:
        using system_t = RemoteControl::DocumentPlugin;
        using process_component_t = RemoteControl::ProcessComponent;
        using process_component_factory_t = RemoteControl::ProcessComponentFactory;
        using process_component_factory_list_t = RemoteControl::ProcessComponentFactoryList;

        using parent_t = ::ConstraintComponentHierarchyManager<
            ConstraintComponent,
            system_t,
            process_component_t,
            process_component_factory_list_t
        >;

        const Key& key() const override;

        ConstraintComponent(
                const Id<Component>& id,
                Scenario::ConstraintModel& constraint,
                const system_t& doc,
                const iscore::DocumentContext& ctx,
                QObject* parent_comp);
        ~ConstraintComponent();

        ProcessComponent* make_processComponent(
                const Id<Component> & id,
                ProcessComponentFactory& factory,
                Process::ProcessModel &process,
                const DocumentPlugin &system,
                const iscore::DocumentContext &ctx,
                QObject *parent_component);

        void removing(const Process::ProcessModel& cst, const ProcessComponent& comp);

        const auto& processes() const
        { return m_baseComponent.processes(); }

    private:
        Mix::ProcessModel* findMix() const;

        parent_t m_baseComponent;
};



}
