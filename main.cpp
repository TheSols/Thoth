#include "mainwindow.h"
#include "QTabWidget"
#include <QApplication>
#include "keyboard.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  Keyboard keyboard;
  w.setCentralWidget(&keyboard);
  w.show();
  return a.exec();
}
