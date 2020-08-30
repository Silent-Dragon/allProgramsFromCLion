#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int sum = 0;
int d;

int sumOfDigits(int n) {
    for (int i = 0; i < 3; i++) {
        d = n % 10;
        sum += d;
        n /= 10;
    }

    cout << sum;
}

int main() {
    int n = 0;
    cin >> n;

    sumOfDigits(n);
}