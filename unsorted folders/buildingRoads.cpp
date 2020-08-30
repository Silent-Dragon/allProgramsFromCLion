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
#include <queue>

using namespace std;

const int N = (int)1e3 + 7;

int n, m, s, f;

vector <int> g[N];
int d[N];
int main() {
    cin >> n >> m >> s >> f;
    /*
        n - #node
        m - #edges
    */
    for (int i = 1; i <= m; i++) {
        int v, u;
        cin >> v >> u;
        /*
            v and u are pairs of connected nodes
            v and u represent an edge
        */
        g[v].push_back(u);
        g[u].push_back(v);
    }

    queue <int> q;
    for (int i = 1; i <= n; i++) {
        d[i] = -1;
    }
    // d[i] = the shortest distance from s to i
    d[s] = 0;
    q.push(s);
    while (q.size() > 0) {
        int top = q.front();
        q.pop();// deletes the very first element from queue
        for (auto to : g[top]) {
            if (d[to] == -1) {
                d[to] = d[top] + 1;
                q.push(to);
            }
        }
    }
    /*
        d: [1, 0, 1, 1, -1, 2, -1]
        q: [4, 6]

        int top = q.front();//3
        q.pop();


        7 8 2 7
        2 1
        2 3
        2 4
        3 5
        3 7
        4 6
        6 7
    */


    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << d[i] << endl;
    }
    // d[v] = -1, if this vertex is not visited yet
    // otherwise d[v] is the distance to V from S
    return 0;
}
/*
5 3
1 2
1 3
4 5

     (1)
    /  \
  (2)   (3)

  4 - 5

*/