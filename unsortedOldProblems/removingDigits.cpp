#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

long long int n = 0;
long long int steps = 0;
long long int currentDigit = 0;
long long int maxDigit = 0;

long long int largestDigit(int number) {
    currentDigit = 0;
    maxDigit = 0;

    while (number) {
        currentDigit = number % 10;
        if (currentDigit > maxDigit) {
            maxDigit = currentDigit;
        }

        number /= 10;
    }

    return maxDigit;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while (n >= 0) {
        if (n == 0) {
            cout << steps << endl;
            break;
        }

        n -= largestDigit(n);
        steps++;
    }

    return 0;
}