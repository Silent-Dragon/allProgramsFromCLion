#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e6 + 7;

int t, n, k;
int dp[N];
int a[N];
int prefixSums[N];

int sum(int start, int end) {
    //here you do whatever computation needed

    if (start == 0) {
        return prefixSums[end];
    } else {
        return prefixSums[end] - prefixSums[start - 1];
    }
}

void DP(int currentIndex) {
    if (currentIndex < k) {
        dp[currentIndex] = sum(0, currentIndex) + (1 - a[currentIndex]);
    } else {
        dp[currentIndex] = min(sum(0, currentIndex) + (1 - a[currentIndex]),
                               dp[currentIndex - k] + sum(currentIndex - k + 1,
                                                          currentIndex - 1) +
                                                          (1 - a[currentIndex]));
    }

    if (currentIndex < n) {
        DP(currentIndex + 1);
    }

    return;
}

int main() {
    cin >> t;

    for (int test = 1; test <= t; test++) {
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefixSums[i] = a[i];
            } else {
                prefixSums[i] = prefixSums[i - 1] + a[i];
            }
        }

        DP(0);

        int minAns = 1e9;
        for (int i = 0; i < n; i++) {
            if (dp[i] + sum(i + 1, n - 1) < minAns) {
                minAns = dp[i] + sum(i + 1, n - 1);
            }
        }

        cout << minAns << endl; q   §a   
    }

}
//fin