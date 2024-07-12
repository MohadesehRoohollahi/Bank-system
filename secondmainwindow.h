#ifndef SECONDMAINWINDOW_H
#define SECONDMAINWINDOW_H

#include <QMainWindow>
#include <fstream>


namespace Ui {
class SecondMainWindow;
}

class SecondMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondMainWindow(QWidget *parent = nullptr);
    ~SecondMainWindow();

private slots:
    void on_SignUpButton_clicked();

private:
    Ui::SecondMainWindow *ui;
};

#endif // SECONDMAINWINDOW_H
