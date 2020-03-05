#include "keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
  QWidget(parent),
  QKey("q","Q", shift),
  WKey("w","W", shift),
  EKey("e","E", shift),
  RKey("r","R", shift),
  TKey("t","T", shift),
  YKey("y","Y", shift),
  UKey("u","U", shift),
  IKey("i","I", shift),
  OKey("o","O", shift),
  PKey("p","P", shift),

  AKey("a","A", shift),
  SKey("s","S", shift),
  DKey("d","D", shift),
  FKey("f","F", shift),
  GKey("g","G", shift),
  HKey("h","H", shift),
  JKey("j","J", shift),
  KKey("k","K", shift),
  LKey("l","L", shift),

  ZKey("z","Z", shift),
  XKey("x","X", shift),
  CKey("v","C", shift),
  VKey("v","V", shift),
  BKey("b","B", shift),
  NKey("n","N", shift),
  MKey("m","M", shift),

  Num1Key("1","!",shift),
  Num2Key("2","@",shift),
  Num3Key("3","#",shift),
  Num4Key("4","$",shift),
  Num5Key("5","%",shift),
  Num6Key("6","^",shift),
  Num7Key("7","&",shift),
  Num8Key("8","*",shift),
  Num9Key("9","(",shift),
  Num0Key("0",")",shift),
  HyphenKey("-","_",shift),
  EqualKey("=","+",shift),
  SpaceKey(" "," ",shift),
  ShiftKey1("Left Shift", "L Shift", shift),
  ShiftKey2("Right Shift", "R Shift", shift)
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

KeyboardButton::KeyboardButton(QString letter, QString alt, ShiftSignal &shift):
  letter(letter),
  alternate(alt),
  shift(shift)
{
  shiftToggled();
}

void KeyboardButton::shiftToggled()
{
  if(shift.shifted()){
    this->setText(alternate);
  } else {
    this->setText(letter);
  }
}

ShiftButton::ShiftButton(QString s1, QString s2, ShiftSignal &shift):
  KeyboardButton(s1,s2,shift)
{
  connect(this, &QPushButton::pressed, this, &ShiftButton::onShift);
}

void ShiftButton::onShift()
{
  shift.toggle();
}
