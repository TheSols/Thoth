#include "shiftsignal.h"

ShiftSignal::ShiftSignal(QObject *parent) : QObject(parent)
{

}

void ShiftSignal::setTrue(){
  if(shift != true){
    emit changed(true);
  }
  shift = true;
}

void ShiftSignal::setFalse(){
  if(shift != false){
    emit changed(false);
  }
  shift = false;
}

const bool &ShiftSignal::shifted(){
  return shift;
}

void ShiftSignal::toggle()
{
  if (shift){
    setFalse();
  } else {
    setTrue();
  }
}

ShiftSignal::~ShiftSignal(){

}
