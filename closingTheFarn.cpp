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

long long int n, m, connectedComponents;

vector <pair <int, int>> graph;
vector <int> minSpanningTree;
long long int parent[N];
long long int order[N];
int visited[N];
vector <int> connections[N];
vector <int> ans;

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

        cin >> startNode >> endNode;

        connections[startNode].push_back(endNode);
        connections[endNode].push_back(startNode);
    }

    /*
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            DFS(i);
            connectedComponents++;
        }

        if (connectedComponents > 1) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
    }*/

    for (int i = 1; i <= n; i++) {
        int newBarn;
        cin >> newBarn;

        makeGroup(newBarn);
        for (auto itr : connections[newBarn]) {
            uniteGroups(newBarn, itr);
        }

        for (int i = 1; i < n; i++) {
            if (findGroup(i) != findGroup(i + 1)) {
                ans.push_back(0);
            } else {
                ans.push_back(1);
            }
        }
    }


    reverse(ans.begin(), ans.end());
    for (auto itr : ans) {
        if (itr == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}