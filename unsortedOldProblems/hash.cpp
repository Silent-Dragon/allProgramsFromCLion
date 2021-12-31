#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

const int N = (int)1e3 + 7;


using namespace std;

int n, m;

vector <int> g[N];
/*
    n - # number of nodes
    m - # number of edges
*/

bool visited[N];
// visited[v] = 1
void dfs(int v) {
    visited[v] = 1;
    for (auto to : g[v]) {
        if (!visited[to]) {
            dfs(to);

    }
    /*
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!visited[to]) dfs(to);
    }*/
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int v, u;
        cin >> v >> u;
        /*
            v and u are pairs of connected nodes
            v and u represenets an edge
        */
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && i == '#') {
            dfs(i);
            ++cnt;
        }
    }
    cout << cnt;
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