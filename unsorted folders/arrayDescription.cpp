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

long long int n = 0, m;
const long long int mod = 1e9 + 7;


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long int dp[n + 1][m + 2];
    memset(dp, 0, sizeof(dp));
    if (a[1] > 0)  {
        dp[1][a[1]] = 1;
    } else {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] > 0) {
            dp[i][a[i]] = (dp[i - 1][a[i]] + dp[i - 1][a[i] - 1] + dp[i - 1][a[i] + 1]) % mod;
        } else {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
            }
        }
    }
    int ans = 0;
    if (a[n] == 0) {
        for (int i = 1; i <= m; i++) {
            ans += dp[n][i];
            ans %= mod;
        }
    } else {
        ans = dp[n][a[n]];
    }
    cout << ans;
    return 0;

}
/*
 *
 * O(n * m)
 */