#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>
#include <random>
#include <iostream>å
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = (int)2e5 + 7;
const int modulo = (int)1e9 + 7;

int n, m, currentNode, endNode, cnt, cycleLength;

vector <int> inputGraph[N];
vector <int> graph[N];
long long int dfsDis[N];
long long int sunDis[N];
long long int par[N];
int was[N];
int cycleNodes[N];
int visited[N];
//int prevMoveForEachCoordinate[N];

void sunDistances (int node) {
   // cout << node << endl;
    for (auto to : graph[node]) {
        if (!cycleNodes[to]) {
            sunDis[to] = sunDis[node] + 1;
            sunDistances(to);
        }
    }
}
void dfs(int v, int p) {
    if (was[v]) return;
    was[v] = 1;
    par[v] = p;
    if (was[inputGraph[v][0]] == 1) {
        int cur = v;
        vector <int> cycle;
        while (1) {
            cycle.push_back(cur);
            cycleNodes[cur] = 1;
            if (cur == inputGraph[v][0]) break;
            cur = par[cur];
        }
        cycleLength = cycle.size();
        for (auto itr : cycle) {
            sunDis[itr] = cycleLength;
        }
    }
    else dfs(inputGraph[v][0], v);
    was[v] = 2;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        endNode = 0;

        cin >> endNode;

        inputGraph[i].push_back(endNode);
        graph[endNode].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (!was[i]) {
            dfs(i, 0);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cycleNodes[i]) {
            sunDistances(i);
            //cout << "Node " << i << " is in the cycle" << endl;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << sunDis[i] << " ";
    }

    return 0;
}

//THIS IS RECURSSIVE DP