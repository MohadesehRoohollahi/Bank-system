#ifndef OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include <QMainWindow>
#include"user.h"

namespace Ui {
class OptionWindow;
}

class OptionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OptionWindow(User & u, QWidget *parent = nullptr);
    ~OptionWindow();

private slots:


    void on_pushButtonOpening_clicked();

    void on_pushButtonWiring_clicked();

    void on_pushButton_4_clicked();

    void on_pushButtonChanging_clicked();

    void on_pushButtonChecking_clicked();

private:
    Ui::OptionWindow *ui;
    User user;
};

#endif // OPTIONWINDOW_H
