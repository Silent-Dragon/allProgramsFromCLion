#include <iostream>

using namespace std;

long long int n = 6;
long long int x = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x;

    int dp[x + 1];
    int a[n + 1];
    //vector <int> coins;
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
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