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

int n, m;

int startingNode, endingNode;

vector <int> graph[N];
int dp[N];
int visited[N];
int prevMoveForEachCoordinate[N];

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

        if (dp[to] != -1e9 && dp[node] < dp[to] + 1) {
            dp[node] = dp[to] + 1;
            //prevMoveForEachCoordinate[to] = node;
            prevMoveForEachCoordinate[node] = to;
        }
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
    fill(dp + 1, dp + n + 1, -1e9);
    dp[endingNode] = 0;

    findingPaths(startingNode);

    //Here you would print the path backwards if you wanted to print the path to get from A to B
    if (dp[startingNode] > 0) {
        cout << dp[startingNode] + 1 << endl;

        vector <int> pathToEnd;
        pathToEnd.push_back(startingNode);

        int backtrackingNode = startingNode;
        while (backtrackingNode != endingNode) {
            pathToEnd.push_back(prevMoveForEachCoordinate[backtrackingNode]);

            backtrackingNode = prevMoveForEachCoordinate[backtrackingNode];
        }

        //reverse(pathToEnd.begin(), pathToEnd.end());
        for (auto itr : pathToEnd) {
            cout << itr << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

