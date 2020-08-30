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
long long int k = 0;
long long int smallestM = 0;

long long int splitingIntoSubarrays(long long int maxSum, int a[]) {
/*
    maxSum = 11
    n = 2
    a[0] = 5, a[1] = 11;
*/
    long long int currentSum = 0;
    long long int groups = 1;

    for (int i = 0; i < n; i++) {
        currentSum += a[i];

        if (currentSum > maxSum) {
            groups++;
            currentSum = a[i];
        }

        if (groups > k) {
            break;
        }

    }
    //cout << "Products made in " << h << " seconds are: " << productsMade << endl;

    return groups;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long int l = *max_element(a, a + n);
    long long int r = 1e18;
    long long int m = 0;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (k >= splitingIntoSubarrays(m, a)) {
            smallestM = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << smallestM;

    return 0;
}