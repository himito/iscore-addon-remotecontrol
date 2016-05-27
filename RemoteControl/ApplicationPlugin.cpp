#include <RemoteControl/ApplicationPlugin.hpp>
#include <RemoteControl/DocumentPlugin.hpp>

#include <core/document/Document.hpp>
#include <core/document/DocumentModel.hpp>

namespace RemoteControl
{
ApplicationPlugin::ApplicationPlugin(
        const iscore::ApplicationContext& app):
    GUIApplicationContextPlugin {app}
{

}


void ApplicationPlugin::on_newDocument(
        iscore::Document* doc)
{
    doc->model().addPluginModel(
                new DocumentPlugin{doc->context(), &doc->model()});

}
}

