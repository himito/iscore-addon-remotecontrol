#include <RemoteControl/ApplicationPlugin.hpp>
#include <RemoteControl/DocumentPlugin.hpp>

#include <core/document/Document.hpp>
#include <core/document/DocumentModel.hpp>

#include <iscore/tools/IdentifierGeneration.hpp>
namespace RemoteControl
{
ApplicationPlugin::ApplicationPlugin(
        const iscore::GUIApplicationContext& app):
    GUIApplicationPlugin {app}
{

}

void ApplicationPlugin::on_createdDocument(
        iscore::Document& doc)
{
    doc.model().addPluginModel(
                new DocumentPlugin{doc.context(), getStrongId(doc.model().pluginModels()), &doc.model()});

}

}

