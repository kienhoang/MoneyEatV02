#ifndef ENTER_H
#define ENTER_H

#include <QObject>

class Enter : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject * obj, QEvent * event);
public:
    Enter();
};

#endif // ENTER_H
