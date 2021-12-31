#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0; //number of songs
int ans = 0;
map <int, int> cnt;

int main() {
  //  freopen("in.txt", "r", stdin);

    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int L = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        while (cnt[a[i]] > 1) {
            // L -> L + 1
            cnt[a[L]]--;
            L++;
        }
        // [L, i]
        ans = max(ans, i - L + 1);
    }

    cout << ans << endl;
/*
  2 pointers
*/

    return 0;
}
