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

void KeyButton::setTarget(QLineEdit *lineedit)
{
  input = lineedit;
}

void KeyButton::shiftToggled()
{
  if(shift.shifted()){
    this->setText(alternate);
  } else {
    this->setText(letter);
  }
}

void KeyButton::setHighlight(bool on, bool forShift)
{
  if(on){
    if(forShift){
      if(shift.locked()){
        this->setStyleSheet("background: #0000FF");
      } else {
        this->setStyleSheet("background: #FF0000");
      }
    }else {
      this->setStyleSheet("background: #FF0000");
    }
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
  if(input){
    QString text = input->text();
    int where = input->cursorPosition();
    text.insert(where,shift.shifted()||shift.capsed()? this->alternate: this->letter);
    input->setText(text);
    input->setFocus();
    input->setCursorPosition(where+1);
  }

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
  connect(this, &QPushButton::pressed, this, &SymbolButton::onPressed);
}


void SymbolButton::onPressed()
{
  if(input){
    QString text = input->text();
    int where = input->cursorPosition();
    text.insert(where,shift.shifted()? this->alternate: this->letter);
    input->setText(text);
    input->setFocus();
    input->setCursorPosition(where+1);
  }

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
  connect(this, &QPushButton::pressed, this, &NumButton::onPressed);
}


void NumButton::onPressed()
{
  if(input){
    QString text = input->text();
    int where = input->cursorPosition();
    text.insert(where,shift.shifted()? this->alternate: this->letter);
    input->setText(text);
    input->setFocus();
    input->setCursorPosition(where+1);
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ShiftButton::ShiftButton(ShiftSignal &shift):
  KeyButton("Shift", "Shift",shift)
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
    this->setHighlight(true,true);
  } else {
    this->setHighlight(false,true);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CapsButton::CapsButton(ShiftSignal &shift):
  KeyButton("Caps Lock", "Caps Lock",shift)
{
  connect(this, &QPushButton::pressed, this, &CapsButton::onCaps);
}

void CapsButton::onCaps()
{
  shift.capsToggle();
  if(shift.capsed()){
    this->setHighlight(true,false);
  } else {
    this->setHighlight(false,false);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BackSpaceButton::BackSpaceButton(ShiftSignal &shift):
  KeyButton("Backspace","BackSpace",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &BackSpaceButton::onPressed);
}


void BackSpaceButton::onPressed()
{
  if(input){
    input->backspace();
    input->setFocus();
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

EnterButton::EnterButton(ShiftSignal &shift):
  KeyButton("Enter","Enter",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &EnterButton::onPressed);
}


void EnterButton::onPressed()
{
  if(input){
    input->setFocus();
    emit input->returnPressed();
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ClearButton::ClearButton(ShiftSignal &shift):
  KeyButton("Clear","Clear",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &ClearButton::onPressed);
}


void ClearButton::onPressed()
{
  if(input){
    input->clear();
    input->setFocus();
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LeftButton::LeftButton(ShiftSignal &shift):
  KeyButton("\u2190","\u2190",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &LeftButton::onPressed);
}


void LeftButton::onPressed()
{
  if(input){
    int where = input->cursorPosition();
    input->setCursorPosition(where-1);
    input->setFocus();
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RightButton::RightButton(ShiftSignal &shift):
  KeyButton("\u2192","\u2192",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &RightButton::onPressed);
}


void RightButton::onPressed()
{
  if(input){
    int where = input->cursorPosition();
    input->setCursorPosition(where+1);
    input->setFocus();
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AllButton::AllButton(ShiftSignal &shift):
  KeyButton("Select All","Select All",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &AllButton::onPressed);
}


void AllButton::onPressed()
{
  if(input){
    input->selectAll();
    input->setFocus();
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LanguageButton::LanguageButton(ShiftSignal &shift):
  KeyButton("Language","Language",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &LanguageButton::onPressed);
}


void LanguageButton::onPressed()
{
  if(input){
    input->setFocus();
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AccentButton::AccentButton(ShiftSignal &shift):
  KeyButton("Accent","Accent",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &AccentButton::onPressed);
}


void AccentButton::onPressed()
{
  if(input){
    input->setFocus();
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TabButton::TabButton(ShiftSignal &shift):
  KeyButton("Tab","Tab",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &TabButton::onPressed);
}


void TabButton::onPressed()
{
  if(input){
    QString text = input->text();
    int where = input->cursorPosition();
    text.insert(where,"    ");
    input->setText(text);
    input->setFocus();
    input->setCursorPosition(where+4);
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


SpaceButton::SpaceButton(ShiftSignal &shift):
  KeyButton(" "," ",shift)
{
  shiftToggled();
  connect(this, &QPushButton::pressed, this, &SpaceButton::onPressed);
}


void SpaceButton::onPressed()
{
  if(input){
    QString text = input->text();
    int where = input->cursorPosition();
    text.insert(where," ");
    input->setText(text);
    input->setFocus();
    input->setCursorPosition(where+1);
  }

  if(shift.locked()){
    //Do Nothing
  } else {
    if(shift.shifted()){
      shift.shiftFalse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
