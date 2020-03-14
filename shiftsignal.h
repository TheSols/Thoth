#ifndef SHIFTSIGNAL_H
#define SHIFTSIGNAL_H

#include <QObject>

class ShiftSignal : public QObject
{
  Q_OBJECT
  bool shift = false;
  bool caps = false;
  bool lock = false;

public:
  ShiftSignal(QObject *parent = nullptr);
  ~ShiftSignal();

  void shiftTrue();
  void shiftFalse();
  void shiftToggle();
  const bool& shifted();

  void capsTrue();
  void capsFalse();
  void capsToggle();
  const bool& capsed();

  void lockTrue();
  void lockFalse();
  void lockedToggle();
  const bool& locked();

signals:
  void shiftChanged(bool shifted);
  void capsChanged(bool capsed);


};

#endif // SHIFTSIGNAL_H
