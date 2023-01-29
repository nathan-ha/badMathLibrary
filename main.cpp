#include <iostream>
#include "bmath.h"
using namespace std;

int main() {
    // cout << sin(11 * 3.14159 / 6) << endl;
    // cout << sin(1) << endl;
    // cout << sin(3.14159265358979 / 2) << endl;
    // cout << pow(10, -4) << endl;
    // cout << sqrt(3921) << endl;
    // cout << nroot(99999991, 5) << endl;
    // cout << tan(3.14159265358979 / 4) << endl;
    drawSine();
    // cout << dtor(rtod(180)) << endl;

    // cout << fpow(199999999999, 0.5) << endl; //continue testing: sqrt approximation gets sloppy at around 1 trillion 
    // cout << fpow(15, 90) << endl; //doesnt work well for large powers

    return 0;
}
