#pragma once
#include <RemoteControl/DocumentPlugin.hpp>
#include <Process/Process.hpp>
#include <iscore/component/Component.hpp>
#include <iscore/component/ComponentFactory.hpp>
#include <Scenario/Document/Components/ProcessComponent.hpp>
#include <iscore_addon_remotecontrol_export.h>

namespace RemoteControl
{
class ISCORE_ADDON_REMOTECONTROL_EXPORT ProcessComponent :
        public Scenario::GenericProcessComponent<DocumentPlugin>
{
    public:
        ProcessComponent(
                Process::ProcessModel& proc,
                DocumentPlugin& doc,
                const Id<iscore::Component>& id,
                const QString& name,
                QObject* parent);

        virtual ~ProcessComponent();
};

template<typename Process_T>
class ProcessComponent_T : public ProcessComponent
{
    public:
        using ProcessComponent::ProcessComponent;

        const Process_T& process() const
        { return static_cast<const Process_T&>(ProcessComponent::process()); }
};

class ISCORE_ADDON_REMOTECONTROL_EXPORT ProcessComponentFactory :
        public iscore::GenericComponentFactory<
            Process::ProcessModel,
            DocumentPlugin,
            ProcessComponentFactory>
{
        ISCORE_ABSTRACT_FACTORY_DECL(
                ProcessComponentFactory,
                "b8a691ea-5352-468d-b78c-04e420c252d1")
    public:
        virtual ~ProcessComponentFactory();
        virtual ProcessComponent* make(
                Process::ProcessModel& proc,
                DocumentPlugin& doc,
                const Id<iscore::Component>&,
                QObject* paren_objt) const = 0;
};

template<
        typename ProcessComponent_T,
        typename Process_T>
class ProcessComponentFactory_T : public ProcessComponentFactory
{
    public:
        using ProcessComponentFactory::ProcessComponentFactory;

        bool matches(
                Process::ProcessModel& p, const DocumentPlugin&) const final override
        {
            return dynamic_cast<Process_T*>(&p);
        }

        ProcessComponent* make(
                Process::ProcessModel& proc,
                DocumentPlugin& doc,
                const Id<iscore::Component>& id,
                QObject* paren_objt) const final override
        {
            return new ProcessComponent_T{static_cast<Process_T&>(proc), doc, id, paren_objt};
        }
};

using ProcessComponentFactoryList =
    iscore::GenericComponentFactoryList<
            Process::ProcessModel,
            DocumentPlugin,
            ProcessComponentFactory>;
}


#define REMOTECONTROL_PROCESS_COMPONENT_FACTORY(FactoryName, Uuid, ProcessComponent, Process) \
class FactoryName final : \
        public RemoteControl::ProcessComponentFactory_T<ProcessComponent, Process> \
{ \
        ISCORE_CONCRETE_FACTORY_DECL(Uuid)  \
};
