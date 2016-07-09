#include "LoopFactory.hpp"
#include "Loop.hpp"

namespace RemoteControl
{
bool LoopComponentFactory::matches(
        Process::ProcessModel& p,
        const DocumentPlugin&) const
{
    return dynamic_cast<::Loop::ProcessModel*>(&p);
}

ProcessComponent*
LoopComponentFactory::make(
        const Id<iscore::Component>& id,
        Process::ProcessModel& proc,
        DocumentPlugin& doc,
        QObject* paren_objt) const
{
    return new Loop(id, static_cast<::Loop::ProcessModel&>(proc), doc, paren_objt);
}

}
