#include "shiftsignal.h"

ShiftSignal::ShiftSignal() : QObject(nullptr)
{
  //All variables initialized in class declaration.
  //Nothing to do.
}

ShiftSignal::~ShiftSignal(){
  //Nothing to delete or do.
}

void ShiftSignal::shiftTrue(){
  if(shift != true){
    shift = true;
    emit shiftChanged(true);
  }
}

void ShiftSignal::shiftFalse(){
  lock = false;
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

void ShiftSignal::lockTrue()
{
  lock = true;
  shiftTrue();
  emit shiftChanged(true); //if shift is true, signal will not emit again, so do it a second time.
}

void ShiftSignal::lockFalse()
{
  shiftFalse();
}

void ShiftSignal::lockedToggle()
{
  if(lock){
    lockFalse();
  } else {
    lockTrue();
  }
}

const bool &ShiftSignal::locked()
{
  return lock;
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
