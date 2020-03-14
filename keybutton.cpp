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

void KeyButton::setHighlight(bool on)
{
  if(on){
    this->setStyleSheet("background: #FF0000");
  } else {
    this->setStyleSheet("");
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LetterButton::LetterButton(QString letter, QString alt, ShiftSignal &shift):
  KeyButton(letter,alt,shift)
{
  shiftToggled();
  connect(&shift,&ShiftSignal::capsChanged, this, &LetterButton::shiftToggled);
  connect(this, &QPushButton::pressed, this, &LetterButton::onPressed);
}


void LetterButton::shiftToggled()
{
  if(shift.capsed() || shift.shifted()){
    this->setText(alternate);
  } else {
    this->setText(letter);
  }
}

void LetterButton::onPressed()
{
  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SymbolButton::SymbolButton(QString letter, QString alt, ShiftSignal &shift):
  KeyButton(letter,alt,shift)
{
  shiftToggled();
  connect(&shift,&ShiftSignal::shiftChanged, this, &SymbolButton::shiftToggled);
  connect(this, &QPushButton::pressed, this, &SymbolButton::onPressed);
}


void SymbolButton::shiftToggled()
{
  if(shift.capsed() || shift.shifted()){
    this->setText(alternate);
  } else {
    this->setText(letter);
  }
}

void SymbolButton::onPressed()
{
  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NumButton::NumButton(QString letter, QString alt, ShiftSignal &shift):
  KeyButton(letter,alt,shift)
{
  shiftToggled();
  connect(&shift,&ShiftSignal::capsChanged, this, &NumButton::shiftToggled);
  connect(this, &QPushButton::pressed, this, &NumButton::onPressed);
}


void NumButton::shiftToggled()
{
  if(shift.capsed() || shift.shifted()){
    this->setText(alternate);
  } else {
    this->setText(letter);
  }
}

void NumButton::onPressed()
{
  if(shift.locked()){
    //Do Nothing
  } else {
    //Do Nothing as well
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ShiftButton::ShiftButton(QString s1, QString s2, ShiftSignal &shift):
  KeyButton(s1,s2,shift)
{
  connect(this, &QPushButton::pressed, this, &ShiftButton::onShift);
  connect(&shift,&ShiftSignal::capsChanged, this, &ShiftButton::shiftToggled);
  connect(this, &ShiftButton::doubleClicked, this, &ShiftButton::shiftLock);
}

void ShiftButton::onShift()
{
  shift.shiftToggle();
}

void ShiftButton::shiftLock()
{
  shift.lockedToggle();
}

void ShiftButton::mouseDoubleClickEvent(QMouseEvent *) {
  emit doubleClicked(true);
}

void ShiftButton::shiftToggled(){
  if(shift.shifted()){
    this->setHighlight(true);
  } else {
    this->setHighlight(false);
  }
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
  if(shift.capsed()){
    this->setHighlight(true);
  } else {
    this->setHighlight(false);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
