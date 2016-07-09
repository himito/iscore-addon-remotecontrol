#pragma once
#include <Scenario/Document/State/StateModel.hpp>
#include <RemoteControl/DocumentPlugin.hpp>

namespace RemoteControl
{
class State final :
        public iscore::Component
{
    public:
        using system_t = RemoteControl::DocumentPlugin;

        State(
                const Id<iscore::Component>& id,
                Scenario::StateModel& state,
                const system_t& doc,
                QObject* parent_comp);

        const Key& key() const override;

        ~State();

    private:

};
}
