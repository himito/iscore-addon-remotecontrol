#include "TimeNode.hpp"
#include <Scenario/Document/TimeNode/Trigger/TriggerModel.hpp>

namespace RemoteControl
{

TimeNode::TimeNode(
        const Id<iscore::Component>& id,
        Scenario::TimeNodeModel& timeNode,
        const DocumentPlugin& doc,
        QObject* parent_comp):
    Component{id, "TimeNodeComponent", parent_comp}
{
}

}
