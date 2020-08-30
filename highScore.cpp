#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <queue>

using namespace std;

int n = 0;
int m = 0;
vector <pair <int, int>> graph[2501];
vector <pair <int, int>> reverseGraph[2501];
vector <int> cyclePath;
long long int dis[2501];
int parentNode[2501];
//bool updated[2501]; we only need the last updated node, not all of the ones that are updated
int lastUpdatedNode;
int startingNode;

vector <int> allLastUpdatedNodesForLastIteration;
int visitedAndDistance[2501];
queue <int> nodes;
bool visited[2501];
bool reverseVisited[2501];

void reverseDfs (int currentNode) {
    reverseVisited[currentNode] = true;

    for (auto itr : reverseGraph[currentNode]) {
        if (!reverseVisited[itr.first]) {
            reverseDfs(itr.first);
        }
    }
}

void dfs (int currentNode) {
    visited[currentNode] = true;

    for (auto itr : graph[currentNode]) {
        if (!visited[itr.first]) {
            dfs(itr.first);
        }
    }
}


void BellmanFord() {
    //   cout << "Inside function" << endl;
    for (int i = 1; i <= n; i++) {
        //  cout << "Iteration " << i << " of loop 1" << endl;
        dis[i] = 1e18;
    }
    dis[startingNode] = 0;
    // cout << dis[startingNode] << endl;

    //  cout << "About to enter loop 2" << endl;
    for (int iterations = 0; iterations < n; iterations++) {
        lastUpdatedNode = -1; //resetting to see if the last updated node changes by the end of the iteration
        for (int i = 1; i <= n; i++) {
            for (auto itr : graph[i]) {
                if (itr.second + dis[i] < dis[itr.first]) {
                    dis[itr.first] = itr.second + dis[i];
                    parentNode[itr.first] = i;
                    lastUpdatedNode = itr.first;
                    if (iterations == n - 1) {
                        allLastUpdatedNodesForLastIteration.push_back(lastUpdatedNode);
                    }
                }
            }
        }
        //  cout << "Finished iteration " << iterations << " with lastUpdatedNode of " << lastUpdatedNode << endl;
    }

    if (lastUpdatedNode == -1) {
        cout << dis[n] * -1 << endl;
        cout << endl;
    } else {
        dfs(1);
        reverseDfs(n);

        for (auto itr : allLastUpdatedNodesForLastIteration) {
            if (reverseVisited[itr] && visited[itr]) {
                cout << -1 << endl;
                exit(0);
            }
        }

        cout << dis[n] * -1 << endl;
    }

    return;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int startNode;
        int endNode;
        int length;

        cin >> startNode >> endNode >> length;
        //cout << startNode << " " << endNode << " " << length << endl;

        length *= -1;
        startingNode = 1;

        graph[startNode].push_back({endNode, length});
        reverseGraph[endNode].push_back({startNode, length});

        startNode = 0;
        endNode = 0;
        length = 0;
    }

    //  cout << startingNode << endl;
    //  cout << "Entering function" << endl;
    BellmanFord();

    return 0;
}
