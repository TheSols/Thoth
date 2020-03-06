#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "keybutton.h"


class Keyboard : public QWidget
{
  QGridLayout layout;
  ShiftSignal shift;

  KeyButton QKey;
  KeyButton WKey;
  KeyButton EKey;
  KeyButton RKey;
  KeyButton TKey;
  KeyButton YKey;
  KeyButton UKey;
  KeyButton IKey;
  KeyButton OKey;
  KeyButton PKey;

  KeyButton AKey;
  KeyButton SKey;
  KeyButton DKey;
  KeyButton FKey;
  KeyButton GKey;
  KeyButton HKey;
  KeyButton JKey;
  KeyButton KKey;
  KeyButton LKey;

  KeyButton ZKey;
  KeyButton XKey;
  KeyButton CKey;
  KeyButton VKey;
  KeyButton BKey;
  KeyButton NKey;
  KeyButton MKey;

  KeyButton Num1Key;
  KeyButton Num2Key;
  KeyButton Num3Key;
  KeyButton Num4Key;
  KeyButton Num5Key;
  KeyButton Num6Key;
  KeyButton Num7Key;
  KeyButton Num8Key;
  KeyButton Num9Key;
  KeyButton Num0Key;
  KeyButton HyphenKey;
  KeyButton EqualKey;

  KeyButton TildeKey;
  KeyButton BackspaceKey;
  KeyButton TabKey;
  KeyButton CapsKey;
  KeyButton CommaKey;
  KeyButton PeriodKey;
  KeyButton ForwSlashKey;
  KeyButton SemiColonKey;
  KeyButton QuoteKey;
  KeyButton OpenBracketKey;
  KeyButton CloseBracketKey;
  KeyButton BackSlashKey;
  KeyButton EnterKey;

  KeyButton SpaceKey;
  ShiftButton ShiftKey1;
  ShiftButton ShiftKey2;

public:
  Keyboard(QWidget *parent = nullptr);

};

#endif // KEYBOARD_H
