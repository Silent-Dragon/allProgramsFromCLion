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

int n, m;

int startingNode, endingNode;

vector <int> graph[N];
int dp[N];
int visited[N];

void findingPaths(int node) {
    if (node == endingNode) {
        return;
    }

    if (visited[node] == 1) {
        return;
    }
    visited[node] = 1;

    for (auto to : graph[node]) {
        if (visited[to] == 0) {
            findingPaths(to);
        }

        dp[node] += dp[to];
        dp[node] %= modulo;
    }
}

int main() {
    cin >> n >> m;

    startingNode = 1;
    endingNode = n;

    for (int i = 1; i <= m; i++) {
        int startNode;
        int endNode;

        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);
    }
    dp[endingNode] = 1;

    findingPaths(startingNode);

    cout << dp[startingNode] % modulo << endl;

    return 0;
}

