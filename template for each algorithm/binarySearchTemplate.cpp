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

long long int functionForBS(long long int m, int a[]) {
    //Here you can either do a specific function or leave this blank if you are doing a simple search

    long long int itemsMade = 0;
    //computations
    return itemsMade;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ;

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