#pragma once
#include <RemoteControl/Scenario/Process.hpp>

namespace RemoteControl
{

class ScenarioFactory final :
        public ProcessComponentFactory
{
        ISCORE_CONCRETE_FACTORY_DECL("f8f343b8-96ab-4f41-946f-56c71a121e75")
        bool matches(
                Process::ProcessModel& p,
                const RemoteControl::DocumentPlugin&) const override;

        ProcessComponent* make(
                const Id<iscore::Component>& id,
                Process::ProcessModel& proc,
                DocumentPlugin& doc,
                QObject* paren_objt) const override;
};
}
