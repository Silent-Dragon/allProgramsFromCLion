#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <queue>

using namespace std;

const int MAXN = (int)1e5 + 7;

int n, m, newGroup;
vector <int> graph[MAXN];
int visited[MAXN];
int groups[MAXN];

void dfs(int node, int group) {
    cout << "At node " << node << " with group " << group << endl;

    for (auto to : graph[node]) {
        if (groups[to] == group) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }

        if (visited[to] == 0) {
            if (group == 1) {
                newGroup = 2;
            } else {
                newGroup = 1;
            }


            cout << "Going to node " << to << " with group " << group << endl;
            groups[to] = newGroup;
            dfs(to, newGroup);
        }
    }

    visited[node] = 1;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        visited[i] = 0;
        groups[i] = 0;

        int startNode;
        int endNode;

        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);

        startNode = 0;
        endNode = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i, 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << groups[i] << " ";
    }
    cout << endl;

    return 0;
}