#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void decToAny(int n, int b) {

    vector <int> digits;

    while (n != 0) {
        digits.push_back(n % b);
        n /= b;
    }
    reverse (digits.begin(), digits.end());

    for (int i = 0; i < digits.size(); i++) {
        cout << digits[i] << ' ';
    }
}

int main() {

    int n = 0;
    cout << "Input decimal number to be converted:";
    cin >> n;
    cout << endl;

    int b = 0;
    cout << "Input new number base:";
    cin >> b;
    cout << endl;

    decToAny(n, b);

    return 0;
}