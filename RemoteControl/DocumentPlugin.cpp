#include <RemoteControl/DocumentPlugin.hpp>

#include <core/document/Document.hpp>
#include <core/document/DocumentModel.hpp>
#include <iscore/document/DocumentInterface.hpp>
namespace RemoteControl
{
DocumentPlugin::DocumentPlugin(
        const iscore::DocumentContext& doc,
        QObject* parent):
    iscore::DocumentPlugin{doc, "RemoteControl::DocumentPlugin", parent}
{
    /*
    con(doc, &iscore::Document::aboutToClose,
        this, &DocumentPlugin::cleanup);

    auto& set = m_context.app.settings<Settings::Model>();
    if(set.getLocalTree())
    {
        create();
    }

    con(set, &Settings::Model::LocalTreeChanged,
        this, [=] (bool b) {
        if(b)
            create();
        else
            cleanup();
    }, Qt::QueuedConnection);
    */
}

DocumentPlugin::~DocumentPlugin()
{
    cleanup();
}

void DocumentPlugin::create()
{
    /*
    if(m_root)
        cleanup();

    auto& doc = m_context.document.model().modelDelegate();
    auto scenar = dynamic_cast<Scenario::ScenarioDocumentModel*>(
                      &doc);
    ISCORE_ASSERT(scenar);
    auto& cstr = scenar->baseScenario().constraint();
    m_root = new ConstraintComponent(
                *m_localDevice,
                getStrongId(cstr.components),
                cstr,
                *this,
                m_context,
                this);
    cstr.components.add(m_root);
    */
}

void DocumentPlugin::cleanup()
{
    /*
    if(!m_root)
        return;

    // Remove the node from local device
    auto it = find_if(
                m_localDevice->children(),
                [&] (const auto& node)
    { return node == m_root->node(); });

    if(it != m_localDevice->children().end())
    {
        m_localDevice->erase(it);
    }

    // Delete
    auto& doc = m_context.document.model().modelDelegate();
    auto scenar = dynamic_cast<Scenario::ScenarioDocumentModel*>(
                      &doc);
    ISCORE_ASSERT(scenar);
    auto& cstr = scenar->baseScenario().constraint();

    cstr.components.remove(m_root);
    m_root = nullptr;
    */
}
}
