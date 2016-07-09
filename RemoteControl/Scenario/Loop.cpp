#include "Loop.hpp"
#include <Scenario/Process/Algorithms/Accessors.hpp>
namespace RemoteControl
{

LoopBase::LoopBase(
        ::Loop::ProcessModel& scenario,
        DocumentPlugin& doc,
        const Id<iscore::Component>& id,
        QObject* parent_obj):
    ProcessComponent_T{scenario, doc, id, "LoopComponent", parent_obj}
{
}

}
