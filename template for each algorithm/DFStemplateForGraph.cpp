#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5;

int n, m;
int connectedComponents;
int visited[N];

vector <int> graph[N];


void DFS(int currentNode) {
    visited[currentNode] = 1;

    for (auto to : graph[currentNode]) {
        if (!visited[to]) {
            DFS(to);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int startNode = 0;
        int endNode = 0;

        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);
        graph[endNode].push_back(startNode);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
            connectedComponents++;
        }
    }

    cout << connectedComponents;
    return 0;
}