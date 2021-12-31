#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;



long long toDecimal(int num[], int base, int digits) {

    long long int sum = 0;

    for (int i = 0; i < digits; i++) {
       sum += num[i] * (long long)pow(base, digits - i - 1);
    }

    cout << sum << endl;
    return sum;
}


int main() {
    freopen ("in.txt", "r", stdin);

    int digits1;
    //cout << "Enter number of digits in first number: ";
    cin >> digits1;
//    cout << endl;

    int base1;
//    cout << "Enter base of first number: ";
    cin >> base1;
//    cout << endl;

    int number1[digits1];
    for (int i = 0; i < digits1; i++) {
//        cout << "Enter digit for place " << i << " in number: ";
        cin >> number1[i];
//        cout << endl;
    }

    int digits2;
//    cout << "Enter number of digits in second number: ";
    cin >> digits2;
//    cout << endl;

    int base2;
//    cout << "Enter base of second number: ";
    cin >> base2;
//    cout << endl;

    int number2[digits2];
    for (int i = 0; i < digits2; i++) {
//        cout << "Enter digit for place " << i << " in second number: ";
        cin >> number2[i];
//        cout << endl;
    }





    if (toDecimal(number1, base1, digits1) == toDecimal(number2, base2, digits2)) {
        cout << "=";
        cout << endl;
    } else if (toDecimal(number1, base1, digits1) > toDecimal(number2, base2, digits2)) {
        cout << ">";
    } else {
        cout << "<";
    }

    return 0;
}