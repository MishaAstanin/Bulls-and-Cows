#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <ctime>
#include <vector>
#include <iterator>
#include <string>
#include <QString>

using namespace std;

double ma;

int b, c, step = 0;

vector  <int> generation(vector <int> a, vector <int> b, int t) {

    if (a.size() == 4) {
		return a;
	}

    if ((a.size() == 0) && (t % b.size() == 0)) {
		return generation(a, b, rand());
	}

    vector <int> ::iterator it = b.begin() + (t % b.size());

	a.push_back(*it);
	b.erase(it);

	return generation(a, b, rand());
}

vector <int> numberarray(int x) {

	vector <int> a(0);

	while (x > 0) {
		a.push_back(x % 10);
		x /= 10;
	}

	return a;
}

int bulls(vector <int> a, vector <int> b) {

	int bk = 0;

    for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) {
			bk++;
		}
	}

	return bk;
}

int cows(vector <int> a, vector <int> b) {

	int ck = 0;

	string s1{}, s2{};

    for (int k = 0; k < a.size(); k++) {
		s1 += to_string(a[k]);
	}

    for (int j = 0; j < b.size(); j++) {
		s2 += to_string(b[j]);
	}

    for (int i = 0; i < a.size(); i++) {
		if ((s1[i] != s2[i]) && (s2.find(s1[i]) != string::npos)) {
			ck++;
		}
	}

	return ck;
}

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_gen_clicked()
{
    srand(time(NULL));

    vector <int> temp = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector <int> result(0);

    result = generation(result, temp, rand());

    ma = result[0]*1000 + result[1]*100 + result[2]*10 + result[3];

    QString stri = QString::number(ma);
    ui->lineEdit_3->setText(stri);
}

void SecondWindow::on_enter_clicked()
{
    step++;

    QString strin = QString::number(step);
    ui->lineEdit_4->setText(strin);

    int countbulls = 0, countcows = 0;

    double firstnumber;

    firstnumber = (ui->lineEdit->text().toDouble());


    vector <int> number(0);

    number = numberarray(firstnumber);
    reverse(number.begin(), number.end());

    vector <int> number2(0);

    number2 = numberarray(ma);
    reverse(number2.begin(), number2.end());

    countbulls = bulls(number2, number);
    countcows = cows(number2, number);

    b = countbulls;
    c = countcows;

    if (b == 4) {
        ui->label_3->setText("       ПОБЕДА!!!");

        step = 0;
    }
    else {
        ui->label_3->setText("Число не угадано");
    }

    QString str1 = QString::number(b);
    QString str2 = QString::number(c);

    QString finalStr = ("Bulls: " + str1 + " ; " + "Cows: " + str2);
    ui->lineEdit_2->setText(finalStr);
}


void SecondWindow::on_result1_clicked()
{

}



void SecondWindow::on_clear_clicked()
{
    ui->lineEdit->setText("");
}
