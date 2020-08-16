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

int n, m, startNode;
vector <pair <int, int>> graph[2501];
vector <int> cyclePath;
long long int dis[2501];
int parentNode[2501];
//bool updated[2501]; we only need the last updated node, not all of the ones that are updated
int lastUpdatedNode;
int startingNode;

void BellmanFord() {
    for (int i = 0; i < n; i++) {
        dis[i] = 25e12;
    }

    for (int iterations = 0; iterations < n - 1; iterations++) {
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

        startNode = lastUpdatedNode;
        for (int i = 1; i <= n; i++) {
            startNode = parentNode[startNode];
        }

        int currentNode = startNode;
        while (parentNode[currentNode] != startNode) {
            cyclePath.push_back(currentNode);
            currentNode = parentNode[currentNode];
        }
        cyclePath.push_back(currentNode);
        cyclePath.push_back(startNode);

        while (!cyclePath.empty()) {
            cout << cyclePath.back() << " ";
            cyclePath.pop_back();
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return;
}

int main() {
    cin >> n >> m;

    startingNode = 0;

    for (int i = 0; i < m; i++) {
        int startNode;
        int endNode;
        int length;

        cin >> startNode >> endNode >> length;

        graph[startNode].push_back({endNode, length});

        startNode = 0;
        endNode = 0;
        length = 0;
    }

    BellmanFord();

    return 0;
}
