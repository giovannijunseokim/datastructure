//
//  Polynomial.h
//  test
//
//  Created by Giovanni Junseo Kim on 2022/09/14.
//
// 헤더 파일 Polynomial.h
#include <cstdio>
#define MAX_DEGREE    80

class Polynomial {
protected:
    int    degree;                    // 최고 차수
    float    coef[MAX_DEGREE];    // 각 항의 계수
public:
    Polynomial() { degree = 0; coef[0]=0.f; }
    
    void scale(int s) {
       for (int i = 0; i <= degree; i++) {
          coef[i] *= s;
       }
    };

    void read() {
        printf("다항식의 최고 차수를 입력하시오: ");
        scanf("%d", &degree);
        printf("각 항의 계수를 입력하시오 (총 %d개) ", degree + 1);
        for (int i = 0; i <= degree; i++)
            scanf("%f", coef + i);
    }

    void add(Polynomial a, Polynomial b) {
        if (a.degree > b.degree) {
            *this = a;
            for (int i = 0; i <= b.degree; i++)
                coef[i + (degree - b.degree)] += b.coef[i];
        } else {
            *this = b;
            for (int i = 0; i <= a.degree; i++)
                coef[i + (degree - a.degree)] += a.coef[i];
        }
    }

    bool isZero() { return degree == 0; }

    void negate() {
        for (int i = 0; i<=degree; i++)
            coef[i] = -coef[i];
    }
};

/* Polynomial_h */
