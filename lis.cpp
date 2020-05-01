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

long long int maxLength;

int main() {
    long long int n = 0;
    cin >> n;

    long long int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long int lis[n];
    lis[0] = 1;

    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
        if (lis[i] > maxLength) {
            maxLength = lis[i];
        }
    }

    cout << maxLength << endl;
    return 0;
}