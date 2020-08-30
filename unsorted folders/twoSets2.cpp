#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
int sum1 = 0;
int cnt = 0;
int memorization[5000];


// Prints sums of all subsets of arr[l..r]
void subsetSums(int ar[], int l, int r, int sum) {
    if (l >= r) {
        if (sum == sum1 / 2) {
            //cout << "Left is " << l << " right is " << r << " and sum is " << sum << endl;
            cnt++;
        }
        return;
    }



    // Subset including ar[l]
    subsetSums(ar, l + 1, r, sum + ar[l]);

    // Subset excluding ar[l]
    subsetSums(ar, l + 1, r, sum);
}

int main() {
    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        sum1 += a[i];
    }

    if (sum1 % 2 != 0) {
        cout << 0 << endl;
    } else {
        subsetSums(a, 1, n - 1, 1);
        cout << cnt << endl;
    }

    return 0;
}