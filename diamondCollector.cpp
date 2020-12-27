#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = (int)2e5 + 7;
long long int n, k, ans;
long long int a[N], leftIndex[N], rightIndex[N], numberOfValuesFromLeft[N], numberOfValuesFromRight[N];

int furthestToLeft(int currentSize) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[i] - a[j] > k) {
            j++;
        }
        leftIndex[i] = j;
    }
    return leftIndex[currentSize];
}

int furthestToRight(int currentSize) {
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (j >= 0 && a[j] - a[i] > k) {
            j--;
        }
        rightIndex[i] = j;
    }
    return rightIndex[currentSize];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //input
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        furthestToLeft(i);
    }

    for (int i = 0; i < n; i++) {
        numberOfValuesFromLeft[i] = i - leftIndex[i] + 1;
        if (i > 0) {
            numberOfValuesFromLeft[i] = max(numberOfValuesFromLeft[i], numberOfValuesFromLeft[i - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        furthestToRight(i);
    }

    for (int i = n - 1; i >= 0; i--) {
        numberOfValuesFromRight[i] = rightIndex[i] - i + 1;
        if(i < n - 1) {
            numberOfValuesFromRight[i] = max(numberOfValuesFromRight[i], numberOfValuesFromRight[i + 1]);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, numberOfValuesFromRight[i] + numberOfValuesFromRight[i + 1]);
    }
    cout << ans << endl;

}