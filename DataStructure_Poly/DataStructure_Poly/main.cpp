//
//  main.cpp
//  DataStructure_Poly
//
//  Created by Giovanni Junseo Kim on 2022/09/21.
//

#include <iostream>
#include "Polynomial.h"
#include <cmath>
#include <cstring>

using namespace std;

class GioPoly : public Polynomial
{
public:
    void scale(int s) {
       for (int i = 0; i <= degree; i++) {
          coef[i] *= s;
       }
    };
    
    void sub(GioPoly a, GioPoly b) {
        if (a.degree > b.degree) {
            *this = a;
            for (int i = 0; i <= b.degree; i++)
                coef[i + (degree - b.degree)] -= b.coef[i];
        }
        else {
            *this = b;
            for (int i = 0; i <= a.degree; i++)
                coef[i + (degree - a.degree)] -= a.coef[i];
        }
        trim();
        if(coef[0] < 0){
            negate();
        }
    }
    void display(char *str = " Poly = ") {
        printf("\t%s", str);
        for (int i = 0; i<degree; i++){
            if(coef[i] == 1){
                printf("x^%d + ", degree - i);
            }
            else if (coef[i] != 0){
                printf("%5.1f x^%d + ", coef[i], degree - i);
            }
        };
        printf("%4.1f\n", coef[degree]);
    }
    void trim(){
        int index = 0;
        while(!coef[index]){
            index++; // 제거해야 할 인덱스의 개수
        }
        if(index!=0){
            int _degree = degree; // 원래 차수
            degree -= index; // 나올 차수
            for(int i = 0; i <= _degree-index; i++){
                coef[i] = coef[i+index];
            }
        }
    }

    void evaluate(float a) {
       int sum = 0;
       for (int i = 0; i <= degree; i++) {
          sum += coef[i] * pow(a, degree - i);
       }
       cout << "\t" << a << " 을(를) 대입하면 값은 " << sum << "\n";
    }
    
};

int main(int argc, const char * argv[]) {
    
    GioPoly a;
    GioPoly b;
    a.read(); b.read();
    a.display(); b.display();
    a.evaluate(1);
    GioPoly c;
    c.sub(a,b);
    c.display();
    
    return 0;
}
