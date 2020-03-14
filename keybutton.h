#ifndef KEYBUTTON_H
#define KEYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "shiftsignal.h"
#include <QMouseEvent>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class KeyButton : public QPushButton  {
  Q_OBJECT

protected:
  QString letter;
  QString alternate;
  ShiftSignal &shift;
  void setHighlight(bool on, bool forShift);

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
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class NumButton : public KeyButton{
  Q_OBJECT
  void onPressed();

public:
  NumButton(QString s1, QString s2, ShiftSignal &shift);
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
protected:
  void mouseDoubleClickEvent(QMouseEvent *);
public:
  ShiftButton(QString s1, QString s2, ShiftSignal &shift);

  Q_SLOT
  void onShift();
  Q_SLOT
  void shiftLock();

signals:
  void doubleClicked(bool lock);

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
