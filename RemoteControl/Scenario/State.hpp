#pragma once
#include <Scenario/Document/State/StateModel.hpp>
#include <RemoteControl/DocumentPlugin.hpp>

namespace RemoteControl
{
class State final :
        public iscore::Component
{
        COMPONENT_METADATA("128668ce-edee-454f-9e5a-3ba07a7d0fa4")
    public:
        State(
                const Id<iscore::Component>& id,
                Scenario::StateModel& state,
                const DocumentPlugin& doc,
                QObject* parent_comp);

};
}
