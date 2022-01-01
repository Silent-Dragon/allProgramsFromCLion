#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 7;

int start, end;
int dp[N];
int visited[N];

void computation(int m) {
    //here you do whatever computation needed
}

int DP(int n) {
    if (n == end) {
        return 0;
    }

    if (visited[n] == 1) {
        return dp[n];
    }
    visited[n] = 1;

    dp[n];
}

int main() {
    cin >> start >> end;

    cout << DP(start);
}
