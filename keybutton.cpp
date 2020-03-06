#include "keybutton.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

KeyButton::KeyButton(QString letter, QString alt, ShiftSignal &shift):
  letter(letter),
  alternate(alt),
  shift(shift)
{
  shiftToggled();
  connect(&shift,&ShiftSignal::shiftChanged, this, &KeyButton::shiftToggled);
}

void KeyButton::shiftToggled()
{
  if(shift.shifted()){
    this->setText(alternate);
  } else {
    this->setText(letter);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LetterButton::LetterButton(QString letter, QString alt, ShiftSignal &shift):
  KeyButton(letter,alt,shift)
{
  shiftToggled();
  connect(&shift,&ShiftSignal::capsChanged, this, &LetterButton::shiftToggled);
}


void LetterButton::shiftToggled()
{
  if(shift.capsed() || shift.shifted()){
    this->setText(alternate);
  } else {
    this->setText(letter);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ShiftButton::ShiftButton(QString s1, QString s2, ShiftSignal &shift):
  KeyButton(s1,s2,shift)
{
  connect(this, &QPushButton::pressed, this, &ShiftButton::onShift);
}

void ShiftButton::onShift()
{
  shift.shiftToggle();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CapsButton::CapsButton(QString s1, QString s2, ShiftSignal &shift):
  KeyButton(s1,s2,shift)
{
  connect(this, &QPushButton::pressed, this, &CapsButton::onCaps);
}

void CapsButton::onCaps()
{
  shift.capsToggle();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
