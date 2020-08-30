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
long long int rightPointer = 0;
long long int leftPointer = 0;

int main() {
    cin >> n >> desiredSum;

    long long int a[n + 1];
    long long int sums[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        sums[i] = 0;
        if (i == 0) {
            sums[i] = a[i];
        } else {
            sums[i] = a[i] + sums[i - 1];
        }
    }

    while (rightPointer < n) {
        long long int currentSum = sums[rightPointer];

        if (leftPointer > 0) {
            //to do
            currentSum -= sums[leftPointer - 1];
        }

        if (currentSum == desiredSum) {
            ans++;
            leftPointer++;
        } else if (currentSum > desiredSum) {
            leftPointer++;
        } else {
            rightPointer++;
        }
    }

    cout << ans << endl;

    return 0;
}
