
#include "inspector/View_Window.hxx"

#include <QApplication>
#include <QMainWindow>


#include <gtest/gtest.h>

TEST(View_Window, init) {

  int argc = 1;
  char* argv[] = {(char*)"test"};

  // Initialize Qt application
  QApplication app(argc, argv);

  // Create View_Window instance
  auto window = std::make_unique<View_Window>(QApplication::activeWindow());

  // Configure the window
  window->setWindowTitle("View_Window - init");
  window->resize(800, 600);

  // Show the window
  window->show();

  // Exec app
  QApplication::exec();

  }