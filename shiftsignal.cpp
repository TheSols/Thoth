#include "shiftsignal.h"

ShiftSignal::ShiftSignal(QObject *parent) : QObject(parent)
{

}

ShiftSignal::~ShiftSignal(){

}

void ShiftSignal::shiftTrue(){
  if(shift != true){
    shift = true;
    emit shiftChanged(true);
  }
}

void ShiftSignal::shiftFalse(){
  if(shift != false){
    shift = false;
    emit shiftChanged(false);
  }
}

void ShiftSignal::shiftToggle()
{
  if (shift){
    shiftFalse();
  } else {
    shiftTrue();
  }
}

const bool &ShiftSignal::shifted(){
  return shift;
}



void ShiftSignal::capsTrue(){
  if(caps != true){
    caps = true;
    emit capsChanged(true);
  }
}

void ShiftSignal::capsFalse(){
  if(caps != false){
    caps = false;
    emit capsChanged(false);
  }
}

void ShiftSignal::capsToggle()
{
  if(caps){
    capsFalse();
  } else {
    capsTrue();
  }
}

const bool &ShiftSignal::capsed(){
  return caps;
}
