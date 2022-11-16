#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rules_clicked()
{
    QMessageBox::information(this, "Правила игры:", "Компьютер загадывает четырехзначное число, не содержащее двух одинаковых цифр! Вы набираете свое число, и компьютер сообщает количество БЫКОВ (точно угаданных цифр, т.е., стоящих на своих местах) и КОРОВ (цифр, которые есть в задуманном числе, но на другом месте).");
}

void MainWindow::on_for_example_clicked()
{
    QMessageBox::information(this, "Пример:", "Пусть загаданное число 5734, а вы набирали 0755. Результат будет 1 БЫК и 2 КОРОВЫ. Игра продолжается до тех пор, пока вы не получите 4 БЫКА.");
}

void MainWindow::on_begin_play_clicked()
{
    SecondWindow window;
    window.setModal(true);
    window.exec();
}
