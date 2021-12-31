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
long long int t = 0;
long long int smallestM = 0;

long long int hours(long long int h, int a[]) {
    long long int productsMade = 0;

    for (int i = 0; i < n; i++) {
        productsMade += h / a[i];
        if (t < productsMade) {
            break;
        }
    }
    //cout << "Products made in " << h << " seconds are: " << productsMade << endl;

    return productsMade;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long int l = 1;
    long long int r = 1e18;
    long long int m = 0;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (t <= hours(m, a)) {
            smallestM = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << smallestM;

    return 0;
}