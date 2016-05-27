#include "Event.hpp"

namespace RemoteControl
{
EventComponent::EventComponent(
        const Id<iscore::Component>& id,
        Scenario::EventModel& event,
        const EventComponent::system_t& doc,
        const iscore::DocumentContext& ctx,
        QObject* parent_comp):
    Component{id, "EventComponent", parent_comp}
{
}

const iscore::Component::Key&EventComponent::key() const
{
    static const Key k{"b8cc40b8-2ab4-4b2d-bddb-8bbf926f5060"};
    return k;
}

EventComponent::~EventComponent()
{
}

}
