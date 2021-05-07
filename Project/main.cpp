//
//  main.cpp
//  BULAJ
//
//  Created by Farkas Bende on 2021. 05. 04..
//

#include <iostream>
#include "Header.h"

using namespace std;


int main() {
    
    char op;
    string p1, p2, rhs;
    QMass sol1, sol2;
    QLen soll1, soll2;
    QTime solt1, solt2;
    QVelocity solv1, solv2;
    QElec sole1,sole2;
    QTemp solT1, solT2;
    QMol solm1, solm2;
    QLum solL1, solL2;
    QAcceleration solgy1, solgy2;
    QForce solF1, solF2;
    QPressure soln1, soln2;
    double num1, num2;

    cout << "Enter an expression: (separated by 'space') "  << endl;
    cin >> num1 >> p1 >> op >> num2 >> p2;
    cout << "Convert to: " << endl;
    cin >> rhs;
    
    kiiras(op, p1, p2, sol1, sol2, soll1, soll2, solt1, solt2, solv1, solv2, sole1, sole2, solT1, solT2, solm1, solm2, solL1, solL2, solgy1, solgy2, solF1, solF2, soln1, soln2, num1, num2, rhs);

    return  0;
}
