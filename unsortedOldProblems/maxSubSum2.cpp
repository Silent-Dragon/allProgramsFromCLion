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
long long int a = 0;
long long int b = 0;
multiset <int> currentOptions;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;

    int a[n];
    int forwardSums[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        forwardSums[i] = a[i];

        if (i > 0) {
            forwardSums[i] += forwardSums[i - 1];
        }

        if (i >= a && i <= b) {
            currentOptions.insert(forwardSums[i])
        }
    }



    return 0;
}
