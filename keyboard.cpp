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
  CKey("c","C", shift),
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

  TildeKey("`","~",shift),
  BackspaceKey(shift),
  TabKey("Tab","Tab",shift),
  CapsKey("Caps Lock","Caps Lock",shift),
  CommaKey(",","<",shift),
  PeriodKey(".",">",shift),
  ForwSlashKey("/","?",shift),
  SemiColonKey(";",":",shift),
  QuoteKey("'","\"",shift),
  OpenBracketKey("[","{",shift),
  CloseBracketKey("]","}",shift),
  BackSlashKey("\\","|",shift),
  EnterKey("Enter","Enter",shift),

  SpaceKey(" "," ",shift),
  ShiftKey1("Shift", "Shift", shift),
  ShiftKey2("Shift", "Shift", shift)

{
  layout.addWidget(&TildeKey,0,0,2,2);
  layout.addWidget(&Num1Key,0,2,2,2);
  layout.addWidget(&Num2Key,0,4,2,2);
  layout.addWidget(&Num3Key,0,6,2,2);
  layout.addWidget(&Num4Key,0,8,2,2);
  layout.addWidget(&Num5Key,0,10,2,2);
  layout.addWidget(&Num6Key,0,12,2,2);
  layout.addWidget(&Num7Key,0,14,2,2);
  layout.addWidget(&Num8Key,0,16,2,2);
  layout.addWidget(&Num9Key,0,18,2,2);
  layout.addWidget(&Num0Key,0,20,2,2);
  layout.addWidget(&HyphenKey,0,22,2,2);
  layout.addWidget(&EqualKey,0,24,2,2);
  layout.addWidget(&BackspaceKey,0,26,2,4);

  layout.addWidget(&TabKey,2,0,2,3);
  layout.addWidget(&QKey,2,3,2,2);
  layout.addWidget(&WKey,2,5,2,2);
  layout.addWidget(&EKey,2,7,2,2);
  layout.addWidget(&RKey,2,9,2,2);
  layout.addWidget(&TKey,2,11,2,2);
  layout.addWidget(&YKey,2,13,2,2);
  layout.addWidget(&UKey,2,15,2,2);
  layout.addWidget(&IKey,2,17,2,2);
  layout.addWidget(&OKey,2,19,2,2);
  layout.addWidget(&PKey,2,21,2,2);
  layout.addWidget(&OpenBracketKey,2,23,2,2);
  layout.addWidget(&CloseBracketKey,2,25,2,2);
  layout.addWidget(&BackSlashKey,2,27,2,3);

  layout.addWidget(&CapsKey,4,0,2,4);
  layout.addWidget(&AKey,4,4,2,2);
  layout.addWidget(&SKey,4,6,2,2);
  layout.addWidget(&DKey,4,8,2,2);
  layout.addWidget(&FKey,4,10,2,2);
  layout.addWidget(&GKey,4,12,2,2);
  layout.addWidget(&HKey,4,14,2,2);
  layout.addWidget(&JKey,4,16,2,2);
  layout.addWidget(&KKey,4,18,2,2);
  layout.addWidget(&LKey,4,20,2,2);
  layout.addWidget(&SemiColonKey,4,22,2,2);
  layout.addWidget(&QuoteKey,4,24,2,2);
  layout.addWidget(&EnterKey,4,26,2,4);

  layout.addWidget(&ShiftKey1,6,0,2,5);
  layout.addWidget(&ZKey,6,5,2,2);
  layout.addWidget(&XKey,6,7,2,2);
  layout.addWidget(&CKey,6,9,2,2);
  layout.addWidget(&VKey,6,11,2,2);
  layout.addWidget(&BKey,6,13,2,2);
  layout.addWidget(&NKey,6,15,2,2);
  layout.addWidget(&MKey,6,17,2,2);
  layout.addWidget(&CommaKey,6,19,2,2);
  layout.addWidget(&PeriodKey,6,21,2,2);
  layout.addWidget(&ForwSlashKey,6,23,2,2);
  layout.addWidget(&ShiftKey2,6,25,2,5);


  layout.addWidget(&SpaceKey,8,9,2,12);

  this->setLayout(&layout);
}

void Keyboard::show(QLineEdit &edit)
{
  QKey.setTarget(&edit);
  WKey.setTarget(&edit);
  EKey.setTarget(&edit);
  RKey.setTarget(&edit);
  TKey.setTarget(&edit);
  YKey.setTarget(&edit);
  UKey.setTarget(&edit);
  IKey.setTarget(&edit);
  OKey.setTarget(&edit);
  PKey.setTarget(&edit);

  AKey.setTarget(&edit);
  SKey.setTarget(&edit);
  DKey.setTarget(&edit);
  FKey.setTarget(&edit);
  GKey.setTarget(&edit);
  HKey.setTarget(&edit);
  JKey.setTarget(&edit);
  KKey.setTarget(&edit);
  LKey.setTarget(&edit);

  ZKey.setTarget(&edit);
  XKey.setTarget(&edit);
  CKey.setTarget(&edit);
  VKey.setTarget(&edit);
  BKey.setTarget(&edit);
  NKey.setTarget(&edit);
  MKey.setTarget(&edit);

  Num1Key.setTarget(&edit);
  Num2Key.setTarget(&edit);
  Num3Key.setTarget(&edit);
  Num4Key.setTarget(&edit);
  Num5Key.setTarget(&edit);
  Num6Key.setTarget(&edit);
  Num7Key.setTarget(&edit);
  Num8Key.setTarget(&edit);
  Num9Key.setTarget(&edit);
  Num0Key.setTarget(&edit);
  HyphenKey.setTarget(&edit);
  EqualKey.setTarget(&edit);

  TildeKey.setTarget(&edit);
  BackspaceKey.setTarget(&edit);
  CapsKey.setTarget(&edit);
  CommaKey.setTarget(&edit);
  PeriodKey.setTarget(&edit);
  ForwSlashKey.setTarget(&edit);
  SemiColonKey.setTarget(&edit);
  QuoteKey.setTarget(&edit);
  OpenBracketKey.setTarget(&edit);
  CloseBracketKey.setTarget(&edit);
  BackSlashKey.setTarget(&edit);
  EnterKey.setTarget(&edit);

  SpaceKey.setTarget(&edit);

}

