#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

map <string, int> cnt;

struct data {
    int day, change, milk;
    string cowName;
};

int main() {
     freopen ("measurement.in", "r", stdin);
     freopen ("measurement.out", "w", stdout);
   // freopen ("in.txt", "r", stdin);

    // data a;
    // cout << a.day << ' ' << a.change << ' ' << a.cowName;

    int n, swaps = 0;
    cin >> n;

    int temp = 0;

    // data a[n + 1];
    data a[n + 1];

/*
4
7 Mildred +3
4 Elsie -1
9 Mildred -1
1 Bessie +2
*/
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> a[i].day >> a[i].cowName >> tmp >> a[i].change;
        a[i].milk = 7;
        // cin >> a[i].change;
        // cin >> a[i].cowName;

        //+7
        // cin >> tmp >> a[i].change;
        if (tmp == '-') {
            a[i].change *= -1;
        }

    }

    while (1) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i].day > a[i + 1].day) {
                swap(a[i], a[i + 1]);
            }
        }
        bool sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i].day > a[i + 1].day) {
                sorted = 0;
            }
        }
        if (sorted) break;
    }

    bool bessie = 1, elsie = 1, mildred = 1;
    for (int i = 0; i < n; ) {
        // i ... r
        int r = i;
        while (r + 1 < n && a[i].day == a[r + 1].day) r++;

        for (int j = i; j <= r; j++) {
            cnt[a[j].cowName] += a[j].change;
        }

        int curMax = max({cnt["Bessie"], cnt["Elsie"], cnt["Mildred"]});
        bool nextBessie = (cnt["Bessie"] == curMax), nextElsie = (cnt["Elsie"] == curMax), nextMildred = (cnt["Mildred"] == curMax);
/*
    bessie, elsie, mildred = {0, 1, 1}
    nextBessie, nextElsie, nextMildred = {1, 1, 0}
*/
        if (nextBessie != bessie || nextElsie != elsie || nextMildred != mildred) {
            swaps++;
        }
        bessie = nextBessie;
        elsie = nextElsie;
        mildred = nextMildred;
        // (i ... r), r + 1
        i = r + 1;
    }

    cout << swaps;
    // n^2, n <= 10^4
    // nlogn, n <= 10^7, sort (a, a + n, cmp)
}