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
//int prevMoveForEachCoordinate[N];

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

        //this is for max path/length
        if (dp[to] != -1e9 && dp[node] < dp[to] + 1) {
            dp[node] = dp[to] + 1;
            //prevMoveForEachCoordinate[node] = to;
        }

        //this is for min path/length
        /*
        if (dp[to] != 1e9 && dp[node] > dp[to] + 1) {
            dp[node] = dp[to] + 1;
            //prevMoveForEachCoordinate[node] = to;
        }
         */

        //total number of paths
        //dp[node] += dp[to];
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
    //for min you would do fill(dp + 1, dp + n + 1, 1e9);

    dp[endingNode] = 0;
    //for total no paths you would do dp[endingNode] = 1;

    findingPaths(startingNode);

    //Here you would print the path forwards if you wanted to print the path to get from A to B

    return 0;
}

//THIS IS RECURSSIVE DP