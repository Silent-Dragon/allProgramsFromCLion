#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;


int n;

int Reverse() {
    int revNum = 0;

    revNum = revNum * 10 + n % 10;
    n = n / 10;

    revNum = revNum * 10 + n % 10;
    n = n / 10;

    revNum = revNum * 10 + n % 10;
    n = n / 10;

    revNum = revNum * 10 + n % 10;
    n = n / 10;


    return revNum;
}
int main() {
    cin >> n;
    cout << abs(n - Reverse()) + 1;
}
