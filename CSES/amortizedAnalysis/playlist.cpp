#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n = 0, ans = 0; //number of songs and the answer stored here
map <int, int> cnt;

int main() {

/// Input
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

/// Method
    int leftPointer = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;

        while (cnt[a[i]] > 1) {
            cnt[a[leftPointer]]--;
            leftPointer++;
        }
        ans = max(ans, i - leftPointer + 1);
    }

/// Output
    cout << ans << endl;
    return 0;
}
