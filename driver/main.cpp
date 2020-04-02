#include "mainwindow.h"
#include "QTabWidget"
#include <QApplication>
#include "keyboard.h"
#include <QLineEdit>

/** This is a driver for you to test the keyboard. */
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;

  QWidget widget;
  QGridLayout layout;
  QLineEdit input;
  Keyboard keyboard;

  layout.addWidget(&input,0,0);
  layout.addWidget(&keyboard,1,0);
  widget.setLayout(&layout);

  keyboard.show(input);

  w.setCentralWidget(&widget);
  w.show();
  return a.exec();
}
