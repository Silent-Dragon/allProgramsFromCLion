#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of players in each row: ";
    cin >> n;
    cout << endl;

    long long dp[n+1][3];
    long long r1[n+1], r2[n+1];

    for (int i = 1 ; i <= n ; i++) {
        cout << "Enter height for player " << i << " in row 1: ";
        cin >> r1[i];
        cout << endl;
    }
    for (int i = 1 ; i <= n ; i++) {
        cout << "Enter height for player " << i << " in row 2: ";
        cin >> r2[i];
        cout << endl;
    }

    dp[1][0] = 0;
    dp[1][1] = r1[1];
    dp[1][2] = r2[1];

    for (int i = 2 ; i <= n ; i++) {
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = max(dp[i-1][2],dp[i-1][0])+r1[i];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1])+r2[i];
    }

    cout << max(max(dp[n][0],dp[n][1]),dp[n][2]);

    return 0;
}