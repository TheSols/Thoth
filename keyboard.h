#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

#include "shiftsignal.h"

class KeyboardButton : public QPushButton  {
  Q_OBJECT
  QString letter;
  QString alternate;

protected:
  ShiftSignal &shift;

public:
  KeyboardButton(QString letter, QString alt, ShiftSignal &shift);
  Q_SLOT
  void shiftToggled();
};

class ShiftButton : public KeyboardButton{
  Q_OBJECT
public:
  ShiftButton(QString s1, QString s2, ShiftSignal &shift);
  Q_SLOT
  void onShift();
};

class Keyboard : public QWidget
{
  QGridLayout layout;
  ShiftSignal shift;

  KeyboardButton QKey;
  KeyboardButton WKey;
  KeyboardButton EKey;
  KeyboardButton RKey;
  KeyboardButton TKey;
  KeyboardButton YKey;
  KeyboardButton UKey;
  KeyboardButton IKey;
  KeyboardButton OKey;
  KeyboardButton PKey;

  KeyboardButton AKey;
  KeyboardButton SKey;
  KeyboardButton DKey;
  KeyboardButton FKey;
  KeyboardButton GKey;
  KeyboardButton HKey;
  KeyboardButton JKey;
  KeyboardButton KKey;
  KeyboardButton LKey;

  KeyboardButton ZKey;
  KeyboardButton XKey;
  KeyboardButton CKey;
  KeyboardButton VKey;
  KeyboardButton BKey;
  KeyboardButton NKey;
  KeyboardButton MKey;

  KeyboardButton Num1Key;
  KeyboardButton Num2Key;
  KeyboardButton Num3Key;
  KeyboardButton Num4Key;
  KeyboardButton Num5Key;
  KeyboardButton Num6Key;
  KeyboardButton Num7Key;
  KeyboardButton Num8Key;
  KeyboardButton Num9Key;
  KeyboardButton Num0Key;
  KeyboardButton HyphenKey;
  KeyboardButton EqualKey;

  KeyboardButton SpaceKey;
  KeyboardButton ShiftKey1;
  KeyboardButton ShiftKey2;

public:
  Keyboard(QWidget *parent = nullptr);

};

#endif // KEYBOARD_H
