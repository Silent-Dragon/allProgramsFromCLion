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

pair <int, int> startCoordinates;
pair <int, int> endCoordinates;

int matrix[N][N];

queue <pair <int, int>> coordinates;
int distanceForEachCoordinate[N][N];
//int prevMoveForEachCoordinate[N][N]; If you want to print the path, then save each coordinate you go to and then print the path backwards

void BFS() {
    //go by distance and keep iterating until one of the coordiantes is the end or you cannot progress more

    memset(distanceForEachCoordinate, -1, sizeof(distanceForEachCoordinate));
    distanceForEachCoordinate[startCoordinates.first][startCoordinates.second] = 0;

    coordinates.push(startCoordinates);

    while (!coordinates.empty()) { //while we can still get to the end
        int x = coordinates.front().first;
        int y = coordinates.front().second;

        if (x + 1 <= n && distanceForEachCoordinate[x + 1][y] == -1) {
            coordinates.push({x + 1, y});
            distanceForEachCoordinate[x + 1][y] = distanceForEachCoordinate[x][y] + 1;
        }
        if (x - 1 > 0 && distanceForEachCoordinate[x - 1][y] == -1) {
            coordinates.push({x - 1, y});
            distanceForEachCoordinate[x - 1][y] = distanceForEachCoordinate[x][y] + 1;
        }
        if (y + 1 <= m && distanceForEachCoordinate[x][y + 1] == -1) {
            coordinates.push({x, y + 1});
            distanceForEachCoordinate[x][y + 1] = distanceForEachCoordinate[x][y] + 1;
        }
        if (y - 1 > 0 && distanceForEachCoordinate[x][y - 1] == -1) {
            coordinates.push({x, y - 1});
            distanceForEachCoordinate[x][y - 1] = distanceForEachCoordinate[x][y] + 1;
        }

        coordinates.pop();
    }

    //Here you would print the path backwards if you wanted to print the path to get from A to B

}


int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];

            //if it is the start
            if (matrix[i][j] == 'A') {
                startCoordinates = {i, j};
            }

            //if it is the end
            if (matrix[i][j] == 'B') {
                endCoordinates = {i, j};
            }

        }
    }

    BFS();

    if (distanceForEachCoordinate[endCoordinates.first][endCoordinates.second] != -1) {
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
 *
 * Graph (shortest path from node X to node Y)
 * Matrix (shortest path from I,J to A,B)
 *
 *
 *
 *
 *
 *
 *
 *
 */