#ifndef IS_CLEAR_MARKED_PID_H
#define IS_CLEAR_MARKED_PID_H

#include <QDialog>

namespace Ui {
class is_clear_marked_pid;
}

class is_clear_marked_pid : public QDialog
{
    Q_OBJECT

public:
    explicit is_clear_marked_pid(QWidget *parent = 0);
    ~is_clear_marked_pid();

private:
    Ui::is_clear_marked_pid *ui;
};

#endif // IS_CLEAR_MARKED_PID_H
