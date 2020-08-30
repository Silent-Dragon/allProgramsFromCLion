#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 7;

int a, b;
int dp[N];
bool wasHere[N];
int count(int n) {
    //dp[n] = count(n)
    //if (n > b) return 1e9;//Case we can't make n to be b
    if (n == b) return 0;
    if (wasHere[n] == 1) return dp[n];
    wasHere[n] = 1;
    // n < b
    int minOperations = 1e9;
    // ans = min(ans, count(n + 1));
    //0 = min(0, count(n + 1));//count(n + 1) = 5
    minOperations = min(minOperations, count(n + 1) + 1);
    if (n * 2 <= b) minOperations = min(minOperations, count(n * 2) + 1);
    if (n * 3 <= b) minOperations = min(minOperations, count(n * 3) + 1);
    dp[n] = minOperations;
    return minOperations;
    /*
        (2) -> 2 + 1, 2 * 2, 2 * 3
        min(count(2 + 1), count(2 * 2), count(2 * 3)) + 1

        ans = min(ans, count(2 + 1))
        ans = min(ans, count(2 * 2))
        ans = min(ans, count(2 * 3))

    */
}
int main() {
    cin >> a >> b;
    cout << count(a);
}
