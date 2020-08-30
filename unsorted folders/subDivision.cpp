#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

long long int n = 0; //size of our sequence
long long int aimSum = 0; //current sum
long long int cnt = 0; //number of subarrays where the sum is able to be divided by n
unordered_map <int, int> appNumber;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    appNumber.max_load_factor(0.25);
    appNumber.reserve(n * 2);

    int a[n];
    int forwardSums[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= n;

        if (a[i] < 0) {
            a[i] += n;
        }

        forwardSums[i] = a[i];

        if (i > 0) {
            forwardSums[i] += forwardSums[i - 1];
            forwardSums[i] %= n;
        }
    }

    appNumber[0]++;
    for (int i = 0; i < n; i++) {
        appNumber[forwardSums[i]]++;

        cnt += appNumber[forwardSums[i]] - 1;
    }

    cout << cnt;

    return 0;
}
