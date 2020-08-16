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

vector <int> list;
int permanentMark[N];
int tempMark[N];

void topologicalSort(int node) {
    //cout << "At node " << node << endl;

    if (permanentMark[node] == 1) {
        //cout << "Already finished this node " << node << endl;
        return;
    }

    if (tempMark[node] == 1) {
        //cycle, not possible to sort topologically
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }

    tempMark[node] = 1;

    for (auto itr : graph[node]) {
        topologicalSort(itr);
    }

    tempMark[node] = 0;
    permanentMark[node] = 1;
    list.push_back(node);
    // cout << "Finished node " << node << endl;
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
    topologicalSort(startingNode);

    fill(dp + 1, dp + n + 1, -1e9);
    //for min you would do fill(dp + 1, dp + n + 1, 1e9);

    dp[endingNode] = 0;
    //for total no paths you would do dp[endingNode] = 1;

    for (auto node : list) {
        for (auto to : graph[node]) {
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

    cout << dp[startingNode] << endl;

    //Here you would print the path forwards if you wanted to print the path to get from A to B

    return 0;
}

//THIS IS ITERATIVE DP