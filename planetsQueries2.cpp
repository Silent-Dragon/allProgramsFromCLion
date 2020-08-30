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

const int N = (int)2e5 + 7;
//const int K = (int)1e9 + 7;
const int LOG = 30; //of K
const int modulo = (int)1e9 + 7;
int n = 0;
int m = 0;

int startingNode, endingNode, inputEndNode, queries;

vector <int> graph[N];

queue <int> coordinates;
int visited[N];
int distanceForEachCoordinate[N];
//int prevMoveForEachCoordinate[N]; If you want to print the path, then save each coordinate you go to and then print the path backwards

void BFS() {
    //go by distance and keep iterating until one of the coordiantes is the end or you cannot progress more

    memset(distanceForEachCoordinate, -1, sizeof(distanceForEachCoordinate));
    distanceForEachCoordinate[startingNode] = 1;

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
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> queries;

    for (int i = 1; i <= n; i++) {
        inputEndNode = 0;

        cin >> inputEndNode;

        graph[i].push_back(inputEndNode);
    }

    startingNode = 1;
    BFS();


    //PROCESS QUERIES AND GET RESULTS FROM COMPUTATION
    for (int q = 1; q <= queries; q++) {
        int startNode, endNode, answer;
        cin >> startNode >> endNode;

        if (distanceForEachCoordinate[startNode] == 0 || distanceForEachCoordinate[endNode] == 0) {
            // We do not have a possible path
            cout << -1 << " ";
        }

        answer = distanceForEachCoordinate[endNode] - distanceForEachCoordinate[startNode];
        cout << answer << " ";
    }
    cout << endl;



    return 0;
}

//THIS IS BFS