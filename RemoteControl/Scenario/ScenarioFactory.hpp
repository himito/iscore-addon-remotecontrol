#pragma once
#include <RemoteControl/Scenario/Process.hpp>

namespace RemoteControl
{

class ScenarioComponentFactory final :
        public ProcessComponentFactory
{
        ISCORE_CONCRETE_FACTORY_DECL("f8f343b8-96ab-4f41-946f-56c71a121e75")
        bool matches(
                Process::ProcessModel& p,
                const RemoteControl::DocumentPlugin&,
                const iscore::DocumentContext&) const override;

        ProcessComponent* make(
                const Id<iscore::Component>& id,
                Process::ProcessModel& proc,
                const DocumentPlugin& doc,
                const iscore::DocumentContext& ctx,
                QObject* paren_objt) const override;
};
}
