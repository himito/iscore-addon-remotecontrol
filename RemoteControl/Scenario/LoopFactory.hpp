#pragma once
#include <RemoteControl/Scenario/Process.hpp>

namespace RemoteControl
{

class LoopComponentFactory final :
        public ProcessComponentFactory
{
        ISCORE_CONCRETE_FACTORY_DECL("5990fe04-4a3d-40c4-bebb-572add54dd44")
        bool matches(
                Process::ProcessModel& p,
                const RemoteControl::DocumentPlugin&,
                const iscore::DocumentContext&) const override;

        ProcessComponent* make(
                const Id<iscore::Component>& id,
                Process::ProcessModel& proc,
                DocumentPlugin& doc,
                const iscore::DocumentContext& ctx,
                QObject* paren_objt) const override;
};
}
