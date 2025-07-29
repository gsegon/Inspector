#include <iostream>

#include <QApplication>

#include <TDocStd_Application.hxx>
#include <BinXCAFDrivers.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <TDataStd_Name.hxx>

#include <inspector/PluginAPI_Communicator.hxx>
#include <inspector/TInspector_Communicator.hxx>


static TInspector_Communicator* aCommunicator;

void CreateInspector(const NCollection_List<Handle(Standard_Transient)>& aParameters)
{

    // Append parameters in the list

    if (!aCommunicator)
    {
        aCommunicator = new TInspector_Communicator();

        aCommunicator->RegisterPlugin("TKDFBrowser");
        // aCommunicator->RegisterPlugin("TKVInspector");
        // aCommunicator->RegisterPlugin("TKShapeView");
        // aCommunicator->RegisterPlugin("TKMessageView");

        aCommunicator->Init(aParameters);
        aCommunicator->Activate("TKDFBrowser");
    }
    aCommunicator->SetVisible(true);
}

int main(int argc, char** argv) {

    // Some Qt App
    QApplication anApp(argc, argv);

    // Some OCAF app
    Handle(TDocStd_Application) app;
    Handle(TDocStd_Document) doc;

    app = new TDocStd_Application();
    BinXCAFDrivers::DefineFormat(app);
    app->NewDocument("BinXCAF", doc);

    TDF_Label some_label = TDF_TagSource::NewChild(doc->Main());
    TDataStd_Name::Set(some_label, "Some Label Name");

    // Add the app to app to inspector init parameters
    NCollection_List<Handle(Standard_Transient)> aParameters;
    aParameters.Append(app);

    // Create inspector
    CreateInspector(aParameters);

    std::cout << "Hello, World!" << std::endl;
    return anApp.exec();
}
