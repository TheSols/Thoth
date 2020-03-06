#ifndef KEYBUTTON_H
#define KEYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "shiftsignal.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class KeyButton : public QPushButton  {
  Q_OBJECT

protected:
  QString letter;
  QString alternate;
  ShiftSignal &shift;
  void setHighlight(bool on);

public:
  KeyButton(QString letter, QString alt, ShiftSignal &shift);
  Q_SLOT
  virtual void shiftToggled();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SymbolButton : public KeyButton{
  Q_OBJECT
  void onPressed();

public:
  SymbolButton(QString s1, QString s2, ShiftSignal &shift);
  Q_SLOT
  void shiftToggled() override;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class LetterButton : public KeyButton{
  Q_OBJECT
  void onPressed();

public:
  LetterButton(QString s1, QString s2, ShiftSignal &shift);
  Q_SLOT
  void shiftToggled() override;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ShiftButton : public KeyButton{
  Q_OBJECT
  void shiftToggled();
public:
  ShiftButton(QString s1, QString s2, ShiftSignal &shift);
  Q_SLOT
  void onShift();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CapsButton : public KeyButton{
  Q_OBJECT
public:
  CapsButton(QString s1, QString s2, ShiftSignal &shift);
  Q_SLOT
  void onCaps();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // KEYBUTTON_H
