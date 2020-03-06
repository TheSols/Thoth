#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "keybutton.h"


class Keyboard : public QWidget
{
  QGridLayout layout;
  ShiftSignal shift;

  LetterButton QKey;
  LetterButton WKey;
  LetterButton EKey;
  LetterButton RKey;
  LetterButton TKey;
  LetterButton YKey;
  LetterButton UKey;
  LetterButton IKey;
  LetterButton OKey;
  LetterButton PKey;

  LetterButton AKey;
  LetterButton SKey;
  LetterButton DKey;
  LetterButton FKey;
  LetterButton GKey;
  LetterButton HKey;
  LetterButton JKey;
  LetterButton KKey;
  LetterButton LKey;

  LetterButton ZKey;
  LetterButton XKey;
  LetterButton CKey;
  LetterButton VKey;
  LetterButton BKey;
  LetterButton NKey;
  LetterButton MKey;

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
  CapsButton CapsKey;
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
