// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<math.h>
using namespace std;
float x1 = 20, x2 = 20, x3 = 20, x4 = 20, x5 = 0, x6 = 0;
float func(float x1, float x2) {
    return(2 * pow(x1, 2) + 0.2 * x1 * x2 + 6 * pow(x2, 2));
}

float gradi[2] = { 0,0 };

void grad(float x1,float x2) {
    gradi[0] = (4 * x1 + 0.2 * x2);
    gradi[1] = (0.2 * x1 + 12 * x2);
}


float norma(float x1,float x2) {
    return(sqrt(pow(x1, 2) + pow(x2, 2)));
}

void uvl(float t) {
    x3 = (x1 - t * gradi[0]);
    x4 = (x2 - t * gradi[1]);
}


int main()
{
    float exp1 = 0.15, exp2 = 0.2, t = 1;
    int k = 0;

    while (k < 11) {
        x5 = x1;
        x6 = x2;
        x1 = x3;
        x2 = x4;
       grad(x1, x2);
       cout << "K= " << k << "\n";
       cout << "grad=" << gradi[0] << "," << gradi[1] << "\n";
       cout << "Norma=" << norma(gradi[0], gradi[1]) << "\n";

        if (norma(gradi[0], gradi[1]) < exp1) {
            cout << "X1= " << x1 << "X2= " << x2 << "F(x)= " << func(x1, x2);
            k = 12;
        }
        else
            if (k >= 10)
                cout << "X1= " << x1 << "X2= " << x2 << "F(x)= " << func(x1, x2);
            else
            {
                uvl(t);
                while ((func(x3, x4) - func(x1, x2)) > 0)
                {
                    cout << "T= " << t << "\n";
                    t = t / 2;
                    uvl(t);
                    cout << "xK+1= " << x3 << "," << x4 << "\n";
                    cout << "F(xk+1)-F(xk)= " << func(x3, x4) << "-" << func(x1, x2) << " = "<< func(x3, x4) - func(x1, x2)<< "\n"; 
                }
                t = 1;
                if (k >= 1) {
                    cout << "||xk+1-xk|| ? eps2 = " << (norma(x3 - x1, x4 - x2)) << "   " << exp2 << " && " << " |F(xk+1)-F(xk)|  eps2 = " << abs(func(x3, x4) - func(x1, x2)) << "  " << exp2 << "||xk+1-xk-1||  eps2 = " << norma(x3 - x5, x4 - x6) << "   " << exp2 << " && " << " |F(xk+1)-F(xk-1)|  eps2 = " << abs(func(x3, x4) - func(x5, x6)) << "  " << exp2 << "\n";
                    if ((norma(x3 - x1, x4 - x2)) < exp2 && (abs(func(x3, x4) - func(x1, x2)) < exp2) && (norma(x3 - x5, x4 - x6) < exp2) && (abs(func(x3, x4) - func(x5, x6)) < exp2)) {
                        cout << " X1= " << x3 << " X2= " << x4 << " F(x)= " << func(x3, x4);
                        k = 12;
                    }
                    else
                    {
                        k++;
                    }
                }
                else k++;
            }

    }

}

// Запус
