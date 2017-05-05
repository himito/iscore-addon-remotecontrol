#pragma once
#include <Scenario/Document/TimeNode/TimeNodeModel.hpp>
#include <RemoteControl/DocumentPlugin.hpp>


namespace RemoteControl
{
class TimeNode final :
        public iscore::Component
{
        COMMON_COMPONENT_METADATA("79bdaa90-7e1d-41e5-ab1a-8f68fd0807bf")
    public:
        TimeNode(
                const Id<iscore::Component>& id,
                Scenario::TimeNodeModel& timeNode,
                const DocumentPlugin& doc,
                QObject* parent_comp);

};
}
