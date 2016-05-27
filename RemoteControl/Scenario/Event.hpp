#pragma once
#include <Scenario/Document/Event/EventModel.hpp>
#include <RemoteControl/DocumentPlugin.hpp>

namespace RemoteControl
{
class EventComponent final :
        public iscore::Component
{

    public:
        using system_t = RemoteControl::DocumentPlugin;

        EventComponent(
                const Id<Component>& id,
                Scenario::EventModel& event,
                const system_t& doc,
                const iscore::DocumentContext& ctx,
                QObject* parent_comp);

        const Key& key() const override;

        ~EventComponent();

    private:
};
}
