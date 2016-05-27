#pragma once
#include <Scenario/Document/State/StateModel.hpp>
#include <RemoteControl/DocumentPlugin.hpp>

namespace RemoteControl
{
class StateComponent final :
        public iscore::Component
{
    public:
        using system_t = RemoteControl::DocumentPlugin;

        StateComponent(
                const Id<iscore::Component>& id,
                Scenario::StateModel& state,
                const system_t& doc,
                const iscore::DocumentContext& ctx,
                QObject* parent_comp);

        const Key& key() const override;

        ~StateComponent();

    private:

};
}
