#ifndef LOG_H
#define LOG_H

#include <QDialog>

namespace Ui {
class Log;
}

class Log : public QDialog
{
    Q_OBJECT

public:
    explicit Log(QWidget *parent = 0);
    ~Log();
    void addEvent(const QString &event);
    void clear();
private:
    Ui::Log *ui;
};

#endif // LOG_H
