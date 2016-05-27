#pragma once
#include <Scenario/Document/TimeNode/TimeNodeModel.hpp>
#include <RemoteControl/DocumentPlugin.hpp>


namespace RemoteControl
{
class TimeNodeComponent final :
        public iscore::Component
{
    public:
        using system_t = RemoteControl::DocumentPlugin;

        TimeNodeComponent(
                const Id<iscore::Component>& id,
                Scenario::TimeNodeModel& timeNode,
                const system_t& doc,
                const iscore::DocumentContext& ctx,
                QObject* parent_comp);

        const Key& key() const override;

        ~TimeNodeComponent();

    private:
};
}
