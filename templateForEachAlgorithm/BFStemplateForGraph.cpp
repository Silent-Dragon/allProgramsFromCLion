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

int n = 0;
int m = 0;

int startingNode, endingNode;

vector <int> graph[N];

queue <int> coordinates;
int distanceForEachCoordinate[N];
//int prevMoveForEachCoordinate[N]; If you want to print the path, then save each coordinate you go to and then print the path backwards

void BFS() {
    //go by distance and keep iterating until one of the coordiantes is the end or you cannot progress more

    memset(distanceForEachCoordinate, -1, sizeof(distanceForEachCoordinate));
    distanceForEachCoordinate[startingNode] = 0;

    coordinates.push(startingNode);

    while (!coordinates.empty()) { //while we can still get to the end
        int currentNode = coordinates.front();

        for (auto to : graph[currentNode]) {
            if (distanceForEachCoordinate[to] == -1) {
                coordinates.push(to);
                distanceForEachCoordinate[to] = distanceForEachCoordinate[currentNode] + 1;
            }
        }

        coordinates.pop();
    }

    //Here you would print the path backwards if you wanted to print the path to get from A to B

}


int main() {
    cin >> n >> m >> startingNode >> endingNode;

    for (int i = 1; i <= n; i++) {
        int startNode;
        int endNode;

        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);

        startNode = 0;
        endNode = 0;
    }

    BFS();

    if (distanceForEachCoordinate[endingNode] != -1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}


/*
 *
 *
 *
 * Graph (shortest path from node X to node Y)
 * Matrix (shortest path from I,J to A,B)
 *
 *
 *
 *
 */