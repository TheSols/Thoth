#ifndef SHIFTSIGNAL_H
#define SHIFTSIGNAL_H

#include <QObject>

///////////////////////////////////////////////////////////////////////////////////
/// \brief The ShiftSignal class
///
/// The ShiftSignal Class is the determines signals whether or not a shift or caps
/// key has been pressed or locked.
///
/// Inherits from QObject for signaling purposes
///////////////////////////////////////////////////////////////////////////////////
class ShiftSignal : public QObject
{
  Q_OBJECT
  /** whether or not the shift key was pressed */
  bool shift = false;
  /** whether or not the caps key was pressed */
  bool caps = false;
  /** whether or not the shift key was locked (double pressed) */
  bool lock = false;

public:
  ShiftSignal();
  ~ShiftSignal();

  /** set shift to true */
  void shiftTrue();
  /** set shift to false */
  void shiftFalse();
  /** if shift is true, set to false. if false, set to true */
  void shiftToggle();
  /** display the current state of shift */
  const bool& shifted();

  /** set caps to true */
  void capsTrue();
  /** set caps to false */
  void capsFalse();
  /** if caps is true, set to false. if false, set to true */
  void capsToggle();
  /** display the current state of caps */
  const bool& capsed();

  /** set lock to true */
  void lockTrue();
  /** set lock to false */
  void lockFalse();
  /** if lock is true, set to false. if false, set to true */
  void lockedToggle();
  /** display the current state of lock */
  const bool& locked();

protected:
signals:
  /** emitted when ever shift is changed */
  void shiftChanged(bool shifted);
  /** emitted when ever caps is changed */
  void capsChanged(bool capsed);

};

#endif // SHIFTSIGNAL_H
