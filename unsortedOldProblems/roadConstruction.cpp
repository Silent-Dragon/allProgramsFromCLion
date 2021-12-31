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

long long int n, m, connectedComponents, maxSizeOfGroup;

vector <pair <int, int>> graph;
vector <int> used;
long long int parent[N];
long long int order[N];
long long int sizeOfGroup[N];

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

    sizeOfGroup[a] += sizeOfGroup[b];
    if (sizeOfGroup[a] > maxSizeOfGroup) {
        maxSizeOfGroup = sizeOfGroup[a];
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int startNode;
        int endNode;

        cin >> startNode >> endNode;
        used[startNode] = 1;
        used[endNode] = 1;

        if (!used[startNode]) {
            makeGroup(startNode);
            sizeOfGroup[startNode] = 1;
        }

        if (!used[endNode]) {
            makeGroup(endNode);
            sizeOfGroup[endNode] = 1;
        }

        graph.push_back({endNode, startNode});
        graph.push_back({startNode, endNode});

        uniteGroups(startNode, endNode);

        int cnt = 0;
        int previousGroup = findGroup(*used.begin());
        for (auto itr : used) {
            if (findGroup(itr) != previousGroup) {
                cnt++;
            }
        }

        cout << maxSizeOfGroup << " " << cnt << endl;
    }



    return 0;
}