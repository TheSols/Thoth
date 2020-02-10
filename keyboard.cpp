#include "keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
  QKey("Q"),
  WKey("W"),
  EKey("E"),
  RKey("R"),
  TKey("T"),
  YKey("Y"),
  UKey("U"),
  IKey("I"),
  OKey("O"),
  PKey("P"),

  AKey("A"),
  SKey("S"),
  DKey("D"),
  FKey("F"),
  GKey("G"),
  HKey("H"),
  JKey("J"),
  KKey("K"),
  LKey("L"),

  ZKey("Z"),
  XKey("X"),
  CKey("C"),
  VKey("V"),
  BKey("B"),
  NKey("N"),
  MKey("M"),

  Num1Key("1"),
  Num2Key("2"),
  Num3Key("3"),
  Num4Key("4"),
  Num5Key("5"),
  Num6Key("6"),
  Num7Key("7"),
  Num8Key("8"),
  Num9Key("9"),
  Num0Key("0"),
  HyphenKey("-"),
  EqualKey("="),
  SpaceKey(" "),
  ShiftKey1("Left Shift"),
  ShiftKey2("Right Shift")
{
  layout.addWidget(&Num1Key,0,0,2,2);
  layout.addWidget(&Num2Key,0,2,2,2);
  layout.addWidget(&Num3Key,0,4,2,2);
  layout.addWidget(&Num4Key,0,6,2,2);
  layout.addWidget(&Num5Key,0,8,2,2);
  layout.addWidget(&Num6Key,0,10,2,2);
  layout.addWidget(&Num7Key,0,12,2,2);
  layout.addWidget(&Num8Key,0,14,2,2);
  layout.addWidget(&Num9Key,0,16,2,2);
  layout.addWidget(&Num0Key,0,18,2,2);
  layout.addWidget(&HyphenKey,0,20,2,2);
  layout.addWidget(&EqualKey,0,22,2,2);

  layout.addWidget(&QKey,2,1,2,2);
  layout.addWidget(&WKey,2,3,2,2);
  layout.addWidget(&EKey,2,5,2,2);
  layout.addWidget(&RKey,2,7,2,2);
  layout.addWidget(&TKey,2,9,2,2);
  layout.addWidget(&YKey,2,11,2,2);
  layout.addWidget(&UKey,2,13,2,2);
  layout.addWidget(&IKey,2,15,2,2);
  layout.addWidget(&OKey,2,17,2,2);
  layout.addWidget(&PKey,2,19,2,2);

  layout.addWidget(&AKey,4,2,2,2);
  layout.addWidget(&SKey,4,4,2,2);
  layout.addWidget(&DKey,4,6,2,2);
  layout.addWidget(&FKey,4,8,2,2);
  layout.addWidget(&GKey,4,10,2,2);
  layout.addWidget(&HKey,4,12,2,2);
  layout.addWidget(&JKey,4,14,2,2);
  layout.addWidget(&KKey,4,16,2,2);
  layout.addWidget(&LKey,4,18,2,2);

  layout.addWidget(&ZKey,6,3,2,2);
  layout.addWidget(&XKey,6,5,2,2);
  layout.addWidget(&CKey,6,7,2,2);
  layout.addWidget(&VKey,6,9,2,2);
  layout.addWidget(&BKey,6,11,2,2);
  layout.addWidget(&NKey,6,13,2,2);
  layout.addWidget(&MKey,6,15,2,2);

  layout.addWidget(&SpaceKey,8,6,2,10);
  layout.addWidget(&ShiftKey1,6,0,2,3);
  layout.addWidget(&ShiftKey2,6,18,2,3);



  this->setLayout(&layout);
}

KeyboardButton::KeyboardButton(QString letter):
  letter(letter)
{
  this->setText(letter);
}
