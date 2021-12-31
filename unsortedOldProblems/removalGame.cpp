#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

long long int maxSum = 0;
vector <int> v;

bool was[5000][5000][3];
long long dp[5000][5000][3];
long long int move(int left, int right, int turn) {
    if (left > right) {
        return 0;
    }
    if (was[left][right][turn]) return dp[left][right][turn];
    was[left][right][turn] = 1;
    // left, right, turn
    // left == right
    if (turn == 1) {
        return dp[left][right][turn] = max(move(left + 1, right, 3 - turn) + v[left], move(left, right - 1, 3 - turn) + v[right]);
    } else {

        return dp[left][right][turn] = min(move(left + 1, right, 3 - turn), move(left, right - 1, 3 - turn));
    }

}

int main() {
    int length;
    cin >> length;

    for (int i = 0; i < length; i++) {
        int m = 0;
        cin >> m;

        v.push_back(m);
    }

    cout << sizeof(dp) / (1024 * 1024) << endl;
    exit(0);

    cout << move(0, length - 1, 1);
    return 0;
}