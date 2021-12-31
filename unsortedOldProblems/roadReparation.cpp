#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = (int)1e5 + 7;
const int modulo = (int)1e9 + 7;

long long int n, m, cost, connectedComponents;

vector <pair <pair <int, int>, int>> graph;
vector <int> graphForDFS[N];
vector <int> minSpanningTree;
long long int parent[N];
long long int order[N];
int visited[N];

void DFS(int currentNode) {
    visited[currentNode] = 1;

    for (auto to : graphForDFS[currentNode]) {
        if (!visited[to]) {
            DFS(to);
        }
    }
}

void makeGroup(int v) {
    parent[v] = v;
    order[v] = 0;
}

int findGroup(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = findGroup(parent[x]);
}

void uniteGroups(int a, int b) {
    a = findGroup(a);
    b = findGroup(b);
    if (a != b) {
        if (order[a] < order[b]) {
            swap(a, b);
        }
        parent[b] = a;

        if (order[a] == order[b]) {
            order[a]++;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int startNode;
        int endNode;
        int length;

        cin >> startNode >> endNode >> length;

        graph.push_back({{length, endNode}, startNode});
        graphForDFS[startNode].push_back(endNode);
        graphForDFS[endNode].push_back(startNode);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            DFS(i);
            connectedComponents++;
        }

        if (connectedComponents > 1) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
    }

    for (int i = 1; i <= n; i++) {
        makeGroup(i);
    }

    sort(graph.begin(), graph.end());


    for (auto itr : graph) {
        if (findGroup(itr.second) != findGroup(itr.first.second)) {
            cost += itr.first.first;
            minSpanningTree.push_back(itr.second);
            uniteGroups(itr.second, itr.first.second);
        }
    }

    cout << cost << endl;

    return 0;
}