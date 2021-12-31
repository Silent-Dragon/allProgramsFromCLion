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

    cin >> n >> x;
    int dp[x + 1];

    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= x; i++) {
        dp[i] = 1e9 + 7;
    }

    dp[0] = 0;

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] + i <= x) {
                dp[a[j] + i] = min(dp[i] + 1, dp[a[j] + i]);
            }
        }
    }


    if (dp[x] == 1e9 + 7) {
        cout << -1;
    } else {
        cout << dp[x];
    }
    cout << endl;

    return 0;
}