#pragma once
#include <Scenario/Document/TimeNode/TimeNodeModel.hpp>
#include <RemoteControl/DocumentPlugin.hpp>


namespace RemoteControl
{
class TimeNode final :
        public iscore::Component
{
    public:
        using system_t = RemoteControl::DocumentPlugin;

        TimeNode(
                const Id<iscore::Component>& id,
                Scenario::TimeNodeModel& timeNode,
                const system_t& doc,
                QObject* parent_comp);

        const Key& key() const override;

        ~TimeNode();

    private:
};
}
