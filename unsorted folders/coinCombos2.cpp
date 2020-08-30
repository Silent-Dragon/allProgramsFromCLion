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
    //vector <int> coins;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= x; i++) {
        dp[i] = 0;
    }
    sort(a, a + n);

    dp[0] = 0;
    /*
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            cout << "i is: " << i << " and coin is " << a[j] << endl;
            if (a[j] + i <= x) {
                dp[a[j] + i]++;
                cout << "Value for " << a[j] + i << " is "  << dp[a[j] + i] << endl;
            }
        }
    }*/


    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - a[i] >= 0) {
                dp[j] = (dp[j] + dp[j - a[i]]) % (int)(1e9 + 7);
            }
        }
    }




    cout << dp[x];

    return 0;
}