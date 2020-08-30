#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

const int MAX_N = (int)2e5 + 7;

int n;

struct event {
    int t, type, id;
    event(int t, int type, int id) : t(t), type(type), id(id) {
        /* t = a;
        type = b;
        id = c; */
    }
};
bool cmp(event a, event b) {
    if (a.t != b.t) return a.t < b.t;
    return a.type < b.type;
}
int main() {
    cin >> n;
    vector <event> a;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        a.push_back(event(l, 1, i));
        a.push_back(event(r + 1, -1, i));
    }
    sort (a.begin(), a.end(), cmp);
    set <int> empty_rooms;
    for (int i = 1; i <= n; i++) {
        empty_rooms.insert(i);
    }
    vector <int> ans(n + 1);
    int mx = 0;
    for (auto it : a) {
        if (it.type == 1) {
            ans[it.id] = *empty_rooms.begin();
            mx = max(mx, ans[it.id]);
            empty_rooms.erase(empty_rooms.begin());
        } else {
            empty_rooms.insert(ans[it.id]);
        }
    }
    cout << mx << "\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}