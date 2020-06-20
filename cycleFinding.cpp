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
long long int dis[2501];
int parentNode[2501];
//bool updated[2501]; we only need the last updated node, not all of the ones that are updated
int lastUpdatedNode;
int startingNode;

void BellmanFord() {
   // cout << "Inside function" << endl;
    for (int i = 0; i < n; i++) {
       // cout << "Iteration " << i << " of loop 1" << endl;
        dis[i] = 1e9;
       // cout << dis[i] << " ";
    }
    dis[startingNode] = 0;
   // cout << dis[startingNode] << endl;

   // cout << "About to enter loop 2" << endl;
    for (int iterations = 0; iterations < n - 1; iterations++) {
      //  cout << "On iteration " << iterations << " with lastUpdatedNode of " << lastUpdatedNode << endl;
        lastUpdatedNode = -1; //resetting to see if the last updated node changes by the end of the iteration
        for (int i = 1; i <= n; i++) {
            for (auto itr : graph[i]) {
                if (itr.second + dis[i] < dis[itr.first]) {
                    dis[itr.first] = itr.second + dis[i];
                    parentNode[itr.first] = i;
                    lastUpdatedNode = itr.first;
                }
            }
        }
    }

    if (lastUpdatedNode != -1) {
        cout << "YES" << endl;
        int currentNode = lastUpdatedNode;
        while (parentNode[currentNode] != lastUpdatedNode) {
            cout << parentNode[currentNode] << " ";
            currentNode = parentNode[currentNode];
        }
        cout << lastUpdatedNode << endl;
    } else {
        cout << "NO" << endl;
    }

    return;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int startNode;
        int endNode;
        int length;

        if (i == 0) {
            startingNode = startNode;
        }

        cin >> startNode >> endNode >> length;
        cout << startNode << " " << endNode << " " << length << endl;

        graph[startNode].push_back({endNode, length});

        startNode = 0;
        endNode = 0;
        length = 0;
    }

    //cout << "Entering function" << endl;
    BellmanFord();

    return 0;
}
