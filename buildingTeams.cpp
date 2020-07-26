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

long long int n, m, newGroup;
vector <long long int> graph[MAXN];
long long int visited[MAXN];
long long int groups[MAXN];

void dfs(int node, int group) {
    //cout << "At node " << node << " with group " << group << endl;
    visited[node] = 1;

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

           // cout << "Going to node " << to << endl;
            groups[to] = newGroup;
           // cout << "Array 'groups' has " << groups[to] << " in place "<< to << endl;
            dfs(to, newGroup);
        }
    }
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
        graph[endNode].push_back(startNode);

        startNode = 0;
        endNode = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            groups[i] = 1;
            dfs(i, 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << groups[i] << " ";
    }
    cout << endl;



   /* for (int i = 1; i <= n; i++) {
        if (groups[i] == 0) {
            cout << "1" << " ";
        } else {
            cout << "2" << " ";
        }
    }
    cout << endl; */
    return 0;
}