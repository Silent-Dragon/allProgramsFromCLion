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
vector <int> minSpanningTree;
long long int parent[N];
long long int order[N];
int visited[N];
int teams[N];

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
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> teams[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int startNode = i;
            int endNode = j;
            int length = teams[i] ^ teams[j];
            graph.push_back({{length, endNode}, startNode});
        }
    }

    for (int i = 1; i <= n; i++) {
        makeGroup(i);
    }

    sort(graph.begin(), graph.end());
    reverse(graph.begin(), graph.end());


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