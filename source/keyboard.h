#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "keybutton.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The Keyboard class
/// The Keyboard Class is my personal keyboard widget that was made using Qt. It offers pretty
/// basic keyboard functionality but is quite easy to understand and modify for your own purposes.
///
/// To use, simply instantiate the keyboard, and then call the show funtion with a QLineEdit as
/// a parameter.
///////////////////////////////////////////////////////////////////////////////////////////////////
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

  NumButton Num1Key;
  NumButton Num2Key;
  NumButton Num3Key;
  NumButton Num4Key;
  NumButton Num5Key;
  NumButton Num6Key;
  NumButton Num7Key;
  NumButton Num8Key;
  NumButton Num9Key;
  NumButton Num0Key;
  SymbolButton HyphenKey;
  SymbolButton EqualKey;

  SymbolButton TildeKey;
  BackSpaceButton BackspaceKey;
  TabButton TabKey;
  CapsButton CapsKey;
  SymbolButton CommaKey;
  SymbolButton PeriodKey;
  SymbolButton ForwSlashKey;
  SymbolButton SemiColonKey;
  SymbolButton QuoteKey;
  SymbolButton OpenBracketKey;
  SymbolButton CloseBracketKey;
  SymbolButton BackSlashKey;
  EnterButton EnterKey;

  SpaceButton SpaceKey;
  ShiftButton ShiftKey1;
  ShiftButton ShiftKey2;

  ClearButton Clear;
  LeftButton Left;
  RightButton Right;
  AllButton SelectAll;
  LanguageButton Language;
  AccentButton Accents;

public:
  Keyboard(QWidget *parent = nullptr);
  void show(QLineEdit &edit);

};

#endif // KEYBOARD_H
