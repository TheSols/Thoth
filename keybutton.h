#ifndef KEYBUTTON_H
#define KEYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "shiftsignal.h"



class KeyButton : public QPushButton  {
  Q_OBJECT
  QString letter;
  QString alternate;

protected:
  ShiftSignal &shift;

public:
  KeyButton(QString letter, QString alt, ShiftSignal &shift);
  Q_SLOT
  void shiftToggled();
};



class ShiftButton : public KeyButton{
  Q_OBJECT
public:
  ShiftButton(QString s1, QString s2, ShiftSignal &shift);
  Q_SLOT
  void onShift();
};

#endif // KEYBUTTON_H
