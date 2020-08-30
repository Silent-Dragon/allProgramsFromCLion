#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
int sum1 = 0;
int cnt = 0;

int main() {
    int n;
    cin >> n;

    int a[n + 1];
    int dp[((n * (n + 1)) / 2) + 1];

    for (int i = 0; i < ((n * (n + 1)) / 2) + 1; i++) {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        sum1 += a[i];
    }

    if (sum1 % 2 != 0) {
        cout << 0 << endl;
        exit(0);
    }

    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = sum1 / 2; j >= 1; j--) {
            if (j - a[i] >= 0) {
                dp[j] = (dp[j] + dp[j - a[i]]) % (int)(1e9 + 7);
            }
        }
    }

    cout << dp[sum1 / 2];

    return 0;
}