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
using ProcessComponent_T = Scenario::GenericProcessComponent_T<ProcessComponent, Process_T>;

class ISCORE_ADDON_REMOTECONTROL_EXPORT ProcessComponentFactory :
        public iscore::GenericComponentFactory<
            Process::ProcessModel,
            DocumentPlugin,
            ProcessComponentFactory>
{
        ISCORE_ABSTRACT_FACTORY("b8a691ea-5352-468d-b78c-04e420c252d1")
    public:
        virtual ~ProcessComponentFactory();
        virtual ProcessComponent* make(
                Process::ProcessModel& proc,
                DocumentPlugin& doc,
                const Id<iscore::Component>&,
                QObject* paren_objt) const = 0;
};

template<
        typename ProcessComponent_T>
class ProcessComponentFactory_T : public ProcessComponentFactory
{
    public:
        using ProcessComponentFactory::ProcessComponentFactory;

        using model_type = typename ProcessComponent_T::model_type;
        using component_type = ProcessComponent_T;

        static auto static_concreteFactoryKey()
        {
            return ProcessComponent_T::static_key().impl();
        }

        ConcreteFactoryKey concreteFactoryKey() const final override
        {
            return ProcessComponent_T::static_key().impl(); // Note : here there is a conversion between UuidKey<Component> and ConcreteFactoryKey
        }

        bool matches(
                Process::ProcessModel& p, const DocumentPlugin&) const final override
        {
            return dynamic_cast<model_type*>(&p);
        }

        ProcessComponent* make(
                Process::ProcessModel& proc,
                DocumentPlugin& doc,
                const Id<iscore::Component>& id,
                QObject* paren_objt) const final override
        {
            return new ProcessComponent_T{static_cast<model_type&>(proc), doc, id, paren_objt};
        }
};

using ProcessComponentFactoryList =
    iscore::GenericComponentFactoryList<
            Process::ProcessModel,
            DocumentPlugin,
            ProcessComponentFactory>;
}
