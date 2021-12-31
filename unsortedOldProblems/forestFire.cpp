#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const long long N = 4e6 + 10;

void bfs();

int n, m, k, res;
queue <int> q;
bool mark[N];

void bfs() {
    while (!q.empty()) {
        int l = q.size();
        for (int i = 0; i < l; i++) {
            int u = q.front();
            q.pop();
            if (u % m != 1 && !mark[u - 1] && u != 1) {
                res = u - 1;
                q.push(u - 1);
                mark[u - 1] = true;
            }
            if (u % m != 0 && !mark[u + 1]) {
                res = u + 1;
                q.push(u + 1);
                mark[u + 1] = true;
            }
            if (u > m && !mark[u - m]) {
                res = u - m;
                q.push(u - m);
                mark[u - m] = true;
            }
            if (u < (n - 1) * m && !mark[u + m]) {
                res = u + m;
                q.push(u + m);
                mark[u + m] = true;
            }
        }
    }
}

int main() {
    freopen ("in.txt", "r", stdin);

    cin >> n >> m;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        int y;
        cin >> x >> y;
        int l = (x - 1) * m + y;
        res = l;
        q.push(l);
        mark[l] = true;
    }

    bfs();

    int x = res/m;

    if (res % m == 0) {
        cout << x << " " << m;
    } else {
        x++;
        cout << x << " " << res % m;
    }

    return 0;
}


