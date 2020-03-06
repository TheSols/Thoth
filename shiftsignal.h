#ifndef SHIFTSIGNAL_H
#define SHIFTSIGNAL_H

#include <QObject>

class ShiftSignal : public QObject
{
  Q_OBJECT
  bool shift = false;

public:
  ShiftSignal(QObject *parent = nullptr);
  void setTrue();
  void setFalse();
  const bool& shifted();
  void toggle();
  ~ShiftSignal();;

signals:
  void changed(bool shifted);

};

#endif // SHIFTSIGNAL_H
