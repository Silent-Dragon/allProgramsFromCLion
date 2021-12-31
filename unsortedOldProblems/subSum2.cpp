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
map <long long int, long long int> appNumber;
long long int aimSum = 0;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> desiredSum;

    long long int a[n + 1];
    long long int forwardSums[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        forwardSums[i] = a[i];

        if (i > 0) {
            forwardSums[i] = a[i] + forwardSums[i - 1];
        }
        appNumber[forwardSums[i]]++;
    }

    for (int i = 0; i < n; i++) {
        aimSum = 0;
        if (i == 0) {
            aimSum = desiredSum;
        } else {
            aimSum = desiredSum + forwardSums[i - 1];
        }

        ans += appNumber[aimSum];
        appNumber[forwardSums[i]]--;
    }

    cout << ans << endl;

    return 0;
}
