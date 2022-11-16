#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_for_example_clicked();

    void on_rules_clicked();

    void on_begin_play_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


