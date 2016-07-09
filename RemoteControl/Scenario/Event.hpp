#pragma once
#include <Scenario/Document/Event/EventModel.hpp>
#include <RemoteControl/DocumentPlugin.hpp>

namespace RemoteControl
{
class Event final :
        public iscore::Component
{

    public:
        using system_t = RemoteControl::DocumentPlugin;

        Event(
                const Id<iscore::Component>& id,
                Scenario::EventModel& event,
                system_t& doc,
                QObject* parent_comp);

        const Key& key() const override;

        ~Event();

    private:
        Path<Scenario::TimeNodeModel> m_parent;
};
}
