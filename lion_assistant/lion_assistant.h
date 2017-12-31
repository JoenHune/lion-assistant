#ifndef LION_ASSISTANT_H
#define LION_ASSISTANT_H

#include <QMainWindow>

namespace Ui {
class lion_assistant;
}

class lion_assistant : public QMainWindow
{
    Q_OBJECT

public:
    explicit lion_assistant(QWidget *parent = 0);
    ~lion_assistant();

private:
    Ui::lion_assistant *ui;
};

#endif // LION_ASSISTANT_H
