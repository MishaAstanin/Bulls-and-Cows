#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_enter_clicked();

    void on_result1_clicked();

    void on_gen_clicked();

    void on_clear_clicked();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
