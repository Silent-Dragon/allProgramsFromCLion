#include <bits/stdc++.h>

using namespace std;

int n;
map <int, int> a;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;

        a[l]++;
        a[r + 1]--;
    }

    int prefSum = 0, maxSum = 0;
    for (auto it : a) {
        prefSum += it.second;
        maxSum = max(maxSum, prefSum);
    }
    cout << maxSum;
    return 0;
}
/*
O(n * log(n))
O(n + maxB)
*/