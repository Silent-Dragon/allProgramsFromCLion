#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>
#include <random>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

const int N = (int)1e5 + 7;

int n = 0;
int m = 0;

int startingNode, endingNode;

vector <int> graph[N];

queue <int> coordinates;
int distanceForEachCoordinate[N];
int prevMoveForEachCoordinate[N]; //If you want to print the path, then save each coordinate you go to and then print the path backwards

void BFS() {
    //go by distance and keep iterating until one of the coordinates is the end or you cannot progress more

    memset(distanceForEachCoordinate, -1, sizeof(distanceForEachCoordinate));
    distanceForEachCoordinate[startingNode] = 1;

    coordinates.push(startingNode);

    while (!coordinates.empty()) { //while we can still get to the end
        int currentNode = coordinates.front();

        for (auto to : graph[currentNode]) {
            if (distanceForEachCoordinate[to] < distanceForEachCoordinate[currentNode] + 1) {
                coordinates.push(to);
                distanceForEachCoordinate[to] = distanceForEachCoordinate[currentNode] + 1;
                prevMoveForEachCoordinate[to] = currentNode;
            }
        }

        coordinates.pop();
    }

    //Here you would print the path backwards if you wanted to print the path to get from A to B
    if (distanceForEachCoordinate[endingNode] != -1) {
        cout << distanceForEachCoordinate[endingNode] << endl;

        vector <int> pathToEnd;
        pathToEnd.push_back(endingNode);

        int backtrackingNode = endingNode;
        while (backtrackingNode != startingNode) {
            pathToEnd.push_back(prevMoveForEachCoordinate[backtrackingNode]);

            backtrackingNode = prevMoveForEachCoordinate[backtrackingNode];
        }

        reverse(pathToEnd.begin(), pathToEnd.end());
        for (auto itr : pathToEnd) {
            cout << itr << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
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

    for (int i = 1; i <= n; i++) {
        random_shuffle(graph[i].begin(), graph[i].end());
    }

    BFS();

    return 0;
}

/*
 *
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