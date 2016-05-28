#include "State.hpp"

namespace RemoteControl
{

State::State(
        const Id<iscore::Component>& id,
        Scenario::StateModel& state,
        const State::system_t& doc,
        const iscore::DocumentContext& ctx,
        QObject* parent_comp):
    Component{id, "StateComponent", parent_comp}
{
}

const iscore::Component::Key&State::key() const
{
    static const Key k{"4b1c9517-b693-4a36-897e-b4fb4299a97f"};
    return k;
}

State::~State()
{
}

}
