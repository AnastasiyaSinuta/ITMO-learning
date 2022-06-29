#include <stdio.h>

double f1(int);
int f2(void);
int f3(void);

int main() {
    int(*pf2)(void); // создание указателя на функции
    pf2 = f2;
    pf2();
    pf2 = f3;
    pf2();
    double(*pf1)(int);
    pf1 = f1;
    pf1(1);
    int(*p_arr[])(void) = { f2, f3 }; // массив указателей на функции
    for (size_t i = 0; i < 2; ++i) {
        p_arr[i]();
    }
    int arr[3] = { (int)f1, (int)f2, (int)f3 }; // так же массив указателей но типа инт
    pf1 = (double(*)(int))arr[0];
    double k = pf1(1);
    printf("%f \n", k);
    for (size_t i = 1; i < 3; ++i) {
        (int(*)())arr[i];
    }

    return 0;
}

double f1(int a) {
    double b = a;
    printf("\ndouble f1(int)");
    return !a ? b : 1. / b;
}
int f2() {
    printf("\nf2 (void)");
    return 200;
}

int f3() {
    printf("\nint f3(void)");
    return 300;
}
