#include "keybutton.h"

KeyButton::KeyButton(QString letter, QString alt, ShiftSignal &shift):
  letter(letter),
  alternate(alt),
  shift(shift)
{
  shiftToggled();
  connect(&shift,&ShiftSignal::changed, this, &KeyButton::shiftToggled);
}

void KeyButton::shiftToggled()
{
  if(shift.shifted()){
    this->setText(alternate);
  } else {
    this->setText(letter);
  }
}

ShiftButton::ShiftButton(QString s1, QString s2, ShiftSignal &shift):
  KeyButton(s1,s2,shift)
{
  connect(this, &QPushButton::pressed, this, &ShiftButton::onShift);
}

void ShiftButton::onShift()
{
  shift.toggle();
}
