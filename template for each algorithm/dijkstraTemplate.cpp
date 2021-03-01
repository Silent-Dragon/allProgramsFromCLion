///Dijkstra's algorithm is an algorithm for
/// finding the shortest paths between nodes in a graph,
/// which may represent, for example, road networks

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
vector <pair <int, int>> graph[N];
long long int arrayShortestDistance[N];
//int prevMoveForEachCoordinate[N];

void dijkstra() {
    while (!setShortestDistance.empty()) {
        currentNode = setShortestDistance.begin()->second;

        for (auto itr : graph[currentNode]) {
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

        graph[startNode].push_back({endNode, length});
    }

    for (int i = 1; i <= n; i++) {
        arrayShortestDistance[i] = 1e15;
    }
    arrayShortestDistance[1] = 0;
    setShortestDistance.insert({0, 1});

    dijkstra();

    //now we can print shortest distance to each node from starting node
    for (int i = 1; i <= n; i++) {
        cout << arrayShortestDistance[i] << " ";
    }
    cout << endl;


    //Here you would print the path forwards if you wanted to print the path to get from A to B

    return 0;
}