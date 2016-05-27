#include "TimeNode.hpp"
#include <Scenario/Document/TimeNode/Trigger/TriggerModel.hpp>

namespace RemoteControl
{

TimeNodeComponent::TimeNodeComponent(
        const Id<iscore::Component>& id,
        Scenario::TimeNodeModel& timeNode,
        const TimeNodeComponent::system_t& doc,
        const iscore::DocumentContext& ctx,
        QObject* parent_comp):
    Component{id, "TimeNodeComponent", parent_comp}
{
}

const iscore::Component::Key&TimeNodeComponent::key() const
{
    static const Key k{"9f580877-efa4-49a8-b1f1-89365c742c53"};
    return k;
}

TimeNodeComponent::~TimeNodeComponent()
{
}

}
