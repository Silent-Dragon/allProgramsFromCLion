#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct data {
    int day, change;
    string cowName;
};

pair <int, pair <string, int> > a[N];

int main() {
    // freopen ("outofplace.in", "r", stdin);
    //freopen ("outofplace.out", "w", stdout);

    // data a;
    // cout << a.day << ' ' << a.change << ' ' << a.cowName;

    int n, temp;
    cin >> n;

    int day[n + 1];
    // data a[n + 1];
    pair <string, string> cowMilk[n + 1];
    int a[n + 1];

    for (int i = 0; i < n; i++) {
        // cin >> a[i].day;

        cin >> a[i].first >> a[i].second.first;
        //(7) (Mildred) -3
        char tmp;
        cin >> tmp >> a[i].second.second;
        if (tmp == '-') a[i].second.second *= -1;

        cin >> day[i];
        cin >> cowMilk[i].first;
        cin >> cowMilk[i].second;
    }

    for (int i = 0; i < n; i++) {
        cout << day[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        if (day[i] > day[i + 1]) {
            swap(day[i], day[i + 1]);
            swap(cowMilk[i].first, cowMilk[i + 1].first);
            swap(cowMilk[i].second, cowMilk[i + 1].second);
        }
    }

    for (int i = 0; i < n; i++) {

    }


}