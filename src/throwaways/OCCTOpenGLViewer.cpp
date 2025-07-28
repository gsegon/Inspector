// main.cpp
#include <QApplication>
#include <QMainWindow>
#include <QSurfaceFormat>

// OpenCascade includes
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Graphic3d_GraphicDriver.hxx>

// For Qt-OpenCascade integration
#include <Aspect_Window.hxx>

#ifdef _WIN32
  #include <WNT_Window.hxx>
#elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
  #include <Cocoa_Window.hxx>
#else
  #include <X11/X.h>  // For Window type
  #include <Xw_Window.hxx>
#endif

// Qt OpenCascade widget
#include <QOpenGLWidget>

// Custom OCCT viewer widget
class OCCTWidget : public QOpenGLWidget {
public:
    OCCTWidget(QWidget* parent = nullptr) : QOpenGLWidget(parent) {
        // We'll initialize everything in initializeGL
    }

    ~OCCTWidget() {
        // Clean up resources
        myView.Nullify();
        myContext.Nullify();
        myViewer.Nullify();
    }

protected:
    void initializeGL() override {
        // Initialize the OpenCascade viewer
        Handle(Aspect_DisplayConnection) displayConnection = new Aspect_DisplayConnection();

        // Create the graphics driver with explicit OpenGL parameters
        Handle(OpenGl_GraphicDriver) graphicDriver = new OpenGl_GraphicDriver(displayConnection);

        // Optional: Set OpenGL driver parameters if needed
        // graphicDriver->ChangeOptions().contextDebug = Standard_True;
        // graphicDriver->ChangeOptions().glslWarnings = Standard_True;

        // Create viewer
        myViewer = new V3d_Viewer(graphicDriver);
        myViewer->SetDefaultLights();
        myViewer->SetLightOn();

        // Create view
        myView = myViewer->CreateView();
        myView->SetBgGradientColors(Quantity_NOC_BLUE1, Quantity_NOC_BLACK, Aspect_GFM_VER);

        // Create interactive context
        myContext = new AIS_InteractiveContext(myViewer);
        myContext->SetDisplayMode(AIS_Shaded, Standard_True);

        // Create platform-specific window
        Handle(Aspect_Window) window;

        #ifdef _WIN32
            // Windows implementation
            window = new WNT_Window((Aspect_Handle)winId());
        #elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
            // macOS implementation
            window = new Cocoa_Window((NSView *)winId());
        #else
            // X11 implementation
            window = new Xw_Window(displayConnection, (Window)winId());
        #endif

        // Set the window
        myView->SetWindow(window);
        if (!myView->Window()->IsMapped()) {
            myView->Window()->Map();
        }

        // Create and display a box now that the context is ready
        createAndDisplayBox();
    }

    void resizeGL(int width, int height) override {
        if (!myView.IsNull()) {
            myView->MustBeResized();
        }
    }

    void paintGL() override {
        if (!myView.IsNull()) {
            myView->Redraw();
        }
    }

private:
    void createAndDisplayBox() {
        // Create a box shape
        TopoDS_Shape boxShape = BRepPrimAPI_MakeBox(10.0, 20.0, 30.0).Shape();

        // Create an AIS_Shape presentation object (which inherits from PrsMgr_PresentableObject)
        Handle(AIS_Shape) aisBox = new AIS_Shape(boxShape);

        // Set display properties
        aisBox->SetColor(Quantity_NOC_RED);
        aisBox->SetDisplayMode(AIS_Shaded);
        aisBox->SetMaterial(Graphic3d_NOM_PLASTIC);

        // Display the box in the interactive context
        myContext->Display(aisBox, Standard_True);

        // Fit view to show the entire box
        myView->FitAll();
        myView->ZFitAll();
    }

private:
    Handle(V3d_Viewer) myViewer;
    Handle(V3d_View) myView;
    Handle(AIS_InteractiveContext) myContext;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Set up OpenGL format for compatibility with OCCT
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 3);  // Request OpenGL 3.3
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);
    
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("OpenCASCADE Box Example");
    mainWindow.resize(800, 600);
    
    OCCTWidget* occWidget = new OCCTWidget(&mainWindow);
    mainWindow.setCentralWidget(occWidget);
    
    mainWindow.show();
    
    return app.exec();
}