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
long long int x = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int dp[x + 1];
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= x; i++) {
        dp[i] = 0;
    }

    dp[0] = 0;

    dp[0] = 1;
    for (int j = 1; j <= x; j++) {
        for (int i = 0; i < n; i++) {
            if (j - a[i] >= 0) {
                dp[j] = (dp[j] + dp[j - a[i]]) % (int)(1e9 + 7);
            }
        }
    }


    cout << dp[x];

    return 0;
}