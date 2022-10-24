//
//  main.cpp
//  Swap
//
//  Created by Giovanni Junseo Kim on 2022/10/19.
//

#include <iostream>

using namespace std;

void swap1(int* px, int* py){
    int tmp;
    cout << "In swap1() \n";
    cout << "px = " << px << " at "<< &px << endl;
    cout << "py = " << py << " at "<< &py << endl;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

void swap2(int x, int y){
    int tmp;
    cout << "In swap2() \n";
    cout << "x = " << x << " at "<< &x << endl;
    cout << "y = " << y << " at "<< &y << endl;
    tmp = x;
    x = y;
    y = tmp;
}

void swap3(int& x, int& y){
    int tmp;
    cout << "In swap3() \n";
    cout << "x = " << x << " at "<< &x << endl;
    cout << "y = " << y << " at "<< &y << endl;
    tmp = x;
    x = y;
    y = tmp;
}

 
int main(int argc, const char * argv[]) {
    
    int a = 1; int b = 2;
    cout << "In main()" << endl;
    cout << "a = " << a << " at "<< &a << endl;
    cout << "b = " << b << " at "<< &b << endl;
    swap2(a,b);
    a = 1; b = 2;
    swap3(a,b);
    a = 1; b = 2;
    swap1(&a, &b);
    
    char A[5] = {'a', 'b', 'c', 'd'};
    cout << "In main() = []" << endl;
    cout << "A = " << A << endl;
    cout << "&A[0] = " << &A[0] << endl;
    cout << "*A = " << *A << endl;
    cout << "*&A[0] = " << *&A[0] << endl;
    cout << "A+1 = " << A+1 << endl;
    cout << "&A[1]" << &A[1] << endl;
    
    cout << "&A = " << &A << endl;
//    A = A+1;
    cout << "A = " << A << endl;
    return 0;
}
