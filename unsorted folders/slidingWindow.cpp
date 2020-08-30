#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long int n = 0; //size of our sequence
long long int desiredSum = 0;
long long int ans = 0;

int main() {
    cin >> n >> desiredSum;

    long long int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = 0; j < n; j++) {
            currentSum += a[j];
            if (currentSum == desiredSum) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
