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

int dp[501][501];

long long int f(int a, int b) {
    if (a == b) {
        return dp[a][b];
    }

    for (int l = 1; l <= a; l++) {
        for (int h = 1; h <= b; h++) {
            for (int i = 1; i < h; i++) {
                dp[l][h] = min(dp[l][h], dp[l][i] + dp[l][h - i] + 1);

                //cout << "L is " << l << " h is " << h << " and i is " << i << endl;
                //cout << dp[l][h] << endl;
            }

            for (int i = 1; i < l; i++) {
                dp[l][h] = min(dp[l][h], dp[i][h] + dp[l - i][h] + 1);

                //cout << "L is " << l << " h is " << h << " and i is " << i << endl;
                //cout << dp[l][h] << endl;
            }
        }
    }

    return dp[a][b];
}
int main() {
    int inputA = 0;
    int inputB = 0;

    for (int i = 0; i < 501; i++) {
        for (int j = 0; j < 501; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1e9;
            }
        }
    }

    cin >> inputA >> inputB;

    cout << f(inputA, inputB);

    return 0;
}