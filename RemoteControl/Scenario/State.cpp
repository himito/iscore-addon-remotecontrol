#include "State.hpp"

namespace RemoteControl
{

StateComponent::StateComponent(
        const Id<iscore::Component>& id,
        Scenario::StateModel& state,
        const StateComponent::system_t& doc,
        const iscore::DocumentContext& ctx,
        QObject* parent_comp):
    Component{id, "StateComponent", parent_comp}
{
}

const iscore::Component::Key&StateComponent::key() const
{
    static const Key k{"4b1c9517-b693-4a36-897e-b4fb4299a97f"};
    return k;
}

StateComponent::~StateComponent()
{
}

}
