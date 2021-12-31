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
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = (int)1e5 + 7;
const int modulo = (int)1e9 + 7;

int n, m, currentNode;

int startingNode, endingNode;

set <pair <long long int, int>> setShortestDistance;
vector <pair <int, int>> inputGraph[N];
vector <int> graph[N];
long long int arrayShortestDistance[N];
int dpMax[N];
int dpMin[N];
int dpTotal[N];
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
        if (dpMax[to] != -1e9 && dpMax[node] < dpMax[to] + 1) {
            dpMax[node] = dpMax[to] + 1;
            //prevMoveForEachCoordinate[node] = to;
        }

        //this is for min path/length
        if (dpMin[to] != 1e9 && dpMin[node] > dpMin[to] + 1) {
            dpMin[node] = dpMin[to] + 1;
            //prevMoveForEachCoordinate[node] = to;
        }

        //total number of paths
        dpTotal[node] += dpTotal[to];
        dpTotal[node] %= modulo;
    }
}

void dijkstra() {
    while (!setShortestDistance.empty()) {
        currentNode = setShortestDistance.begin()->second;

        for (auto itr : inputGraph[currentNode]) {
            if (arrayShortestDistance[currentNode] + itr.second < arrayShortestDistance[itr.first]) {
                setShortestDistance.erase({arrayShortestDistance[itr.first], itr.first});
                arrayShortestDistance[itr.first] = arrayShortestDistance[currentNode] + itr.second;
                setShortestDistance.insert({arrayShortestDistance[itr.first], itr.first});
            }
        }

        setShortestDistance.erase(setShortestDistance.begin());
    }
}


int main() {
    cin >> n >> m;

    startingNode = 1;
    endingNode = n;

    for (int i = 1; i <= m; i++) {
        int startNode;
        int endNode;
        int length;

        cin >> startNode >> endNode >> length;

        inputGraph[startNode].push_back({endNode, length});
    }

    for (int i = 1; i <= n; i++) {
        arrayShortestDistance[i] = 1e15;
    }
    arrayShortestDistance[1] = 0;
    setShortestDistance.insert({0, 1});

    dijkstra();

    for (int i = 1; i <= n; i++) {
        for (auto to : inputGraph[i]) {
            if (arrayShortestDistance[i] + to.second == arrayShortestDistance[to.first]) {
                graph[i].push_back(to.first);
            }
        }
    }

    //for max you would do
    fill(dpMax + 1, dpMax + n + 1, -1e9);
    //for min you would do
    fill(dpMin + 1, dpMin + n + 1, 1e9);

    //for max you would do
    dpMax[endingNode] = 0;
    //for min you would do
    dpMin[endingNode] = 0;
    //for total no paths you would do
    dpTotal[endingNode] = 1;

    findingPaths(startingNode);

    //minimum price
    cout << arrayShortestDistance[endingNode] << " ";
    cout << dpTotal[startingNode] % modulo << " ";
    cout << dpMin[startingNode] << " ";
    cout << dpMax[startingNode] << endl;


    //Here you would print the path forwards if you wanted to print the path to get from A to B

    return 0;
}

//THIS IS RECURSSIVE DP