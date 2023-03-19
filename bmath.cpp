#include <iostream>
#include <fstream>
#include "bmath.h"

using namespace std;

void drawSine() {

    ofstream fout;
    int scale = 60;
    double AS;

    fout.open("sin.txt");

    if (fout.fail()) {
        cout << "drawSine() ofstream failed\n";
        return;
    }

    for (double x = 0; x < 50; x += 0.1) {

        AS = scale * sin(x);

        if (AS <= 0) {
            // fout << "*\n";
            for (double i = 0; i < scale + AS; i++) { //Distance from the vertical x-axis is: A - (-Asin(x)), where A is the scale
                fout << ' ';
            }
        }
        else {

            for (int i = 0; i < scale; i++) { //turns the scale into the center line
                fout << ' ';
            }
        
            for (double i = 0; i < AS; i++) {
                fout << ' ';
            }
        }

        fout << '*' << endl;

    }    
    fout.close();
}

double pow(double x, int y) { //only works if y is an integer
    double sum = x;

    if (y == 0) {
        return 1;
    }
    else if (y < 0) {

        for (int i = 0; i < -y - 1; i++) {
            sum *= x;
        }
        return 1 / sum;
    }
    else {

        for (int i = 0; i < y - 1; i++) {
            sum *= x;
        }

        return sum;
    }
}

// double abs(double x) {
//     if (x < 0) {
//         return -x;
//     }

//     return x;
// }

double fact(int x) {
    int result = 1;
    for (int i = 0; i < x; i++) {
        result *= (i + 1);
    }
    return result;
}

double exp(int x) {
    return pow(2.718281828, x);
}

double sin(double x) {

    const double pi = 3.14159265358979;

    //convert angle to 0 < x < 2pi
    while (x < 0) {
        x += 2 * pi;
    }
    while (x > 2*pi) {
        x -= 2 * pi;
    }

    //return number based on quadrant of angle
    if (0 <= x && x <= 0.5*pi) {
        return (x - (x*x*x * 0.16666666666) + (x*x*x*x*x * 0.00833333333) - (x*x*x*x*x*x*x * 0.00019841269));

    }
    else if (0.5*pi < x && x <= pi) {
        x = pi - x;
        return (x - (x*x*x * 0.16666666666) + (x*x*x*x*x * 0.00833333333) - (x*x*x*x*x*x*x * 0.00019841269));

    }
    else if (pi < x && x <= 1.5*pi) {
        x -= pi;
        return -(x - (x*x*x * 0.16666666666) + (x*x*x*x*x * 0.00833333333) - (x*x*x*x*x*x*x * 0.00019841269));

    }
    else {
        x = 2*pi - x;
        return -(x - (x*x*x * 0.16666666666) + (x*x*x*x*x * 0.00833333333) - (x*x*x*x*x*x*x * 0.00019841269));

    }

    cout << "sin(x) error" << endl;
    return 0;

}

double cos(double x) {
    return sin(x + 0.5 * 3.14159265358979);
}

double tan(double x) {
    return sin(x) / cos(x);
}

double sec(double x) {
    return 1.0 / cos(x);
}

double csc(double x) {
    return 1.0 / sin(x);
}

double cot(double x) {
    return 1.0 / tan(x);
}

double sqrt(double a) {
    double x = 1;
    for (int i = 0; i < 10; i++) {
        x = x - (x*x - a) / (2*x);
    }
    return x;
}

double nroot(double a, int n) {
    double x = 1;

    if (n > 14) {
        for (int i = 0; i < 5000; i++) {
            x = x - (pow(x, n) - a) / (n * pow(x, n - 1));
        }
        return x;
    }
    else {
        for (int i = 0; i < 20; i++) {
            x = x - (pow(x, n) - a) / (n * pow(x, n - 1));
        }
        return x;
    }
}

// double ln(double x) {
//     for (int i = 1; i < )
// }

double dtor(double x) {
    return x * 0.01745329251;
}
double rtod(double x) {
    return x * 57.2957795131;
}

//gcd using a recursive euclid's algorithm
unsigned gcf(unsigned p, unsigned q) { 
    if (p == 0 || q == 0) return 0;
    if (p > q) {
        if (p % q == 0) return q;
        return gcf(q, p % q);
    }
    if (q % p == 0) return p;
    return gcf(p, q % p);
}

double fpow(double a, double ntemp) {

    long n;
    long d = 10000000;
    ntemp *= d;
    n = ntemp;
    
    // cout << "n: " << ntemp << endl;
    // cout << "d: " << d << endl;
    
    unsigned gcd = gcf(n, d);
    //simplifies fraction
    n /= gcd;
    d /= gcd;

    // cout << "n: " << ntemp << endl;
    // cout << "d: " << d << endl;

    return pow(nroot(a, d), n);

}


void printPi() {
/*
* Calculate Pi using Bailey–Borwein–Plouffe formula 
* source: https://giordano.github.io/blog/2017-11-21-hexadecimal-pi/
*/

}
