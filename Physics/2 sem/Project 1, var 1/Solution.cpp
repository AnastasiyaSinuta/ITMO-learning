#include <iostream>
#include <math.h>

using namespace std;

constexpr auto M_PI = 3.14159265358979323846;
const double pi = M_PI;
double g = 9.8;     //Ускорение свободного падения

void Task1()
{
    cout << "Задание 1.1 а):" << endl;
    cout << "------------------------------------" << endl;
    cout << "Известны начальная скорость мяча V0 и угол a от оси OX, под которым бросили мяч." << endl;
    cout << "Найти координату x точки, в которой приземлится мяч." << endl;
    cout << "------------------------------------" << endl;
    cout << "Введите значения V0(м/с) и a(°) через пробел: ";
    double  V0, a, x;
    cin >> V0 >> a;
    a = a * pi / 180;
    double t = V0 * sin(a) / 9;
    x = 2 * V0 * cos(a) * t;
    cout << "Ответ: " << x << " м" << endl << endl << endl;
}
void Task2()
{
    cout << "Задание 1.1 б):" << endl;
    cout << "------------------------------------" << endl;
    cout << "Известны координаты x и y точки, в которой находится кольцо." << endl;
    cout << "Найти начальную скорость мяча V0 и угол a от оси OX, под которым нужно бросить мяч, чтобы забросить в кольцо." << endl;
    cout << "------------------------------------" << endl;
    cout << "Введите x(м) и y(м) через пробел: ";
    int x, y;
    cin >> x >> y;
    double t = sqrt(2 * y / g);
    double a = atan(x / (g * t * t));
    double V0 = g * t / sin(a);
    a = a * 180 / pi;
    cout << "Ответ: " << V0 << " м/c, " << a << "°" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Task1();
    Task2();
}
