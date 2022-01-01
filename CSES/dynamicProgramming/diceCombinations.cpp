#include <iostream>

using namespace std;

long long int n = 6;
long long int x = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

///Input
    cin >> x; //aim sum

///Method
    int dp[x + 1];
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1; //each place in the array is its value indexed by 1 (all possible options on a dice, 1 to 6)
    }

    for (int i = 1; i <= x; i++) {
        dp[i] = 0; //all places in the array dp are set to 0...
    }

    dp[0] = 1; //apart from the first place in the array, which has a value of 1
    for (int j = 1; j <= x; j++) { //go through all values from 1 to x, our aim sum
        for (int i = 0; i < n; i++) { //and then for each of these values, go through values 0 to 6
            if (j - a[i] >= 0) { //if the value minus the die roll is not less than 0...
                dp[j] = (dp[j] + dp[j - a[i]]) % (int)(1e9 + 7); //...we can use it to calculate answer for current value
            }
        }
    }


/// Output
    cout << dp[x] << endl;
    return 0;
}