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

int startI = 0;
int startJ = 0;
int endI = 0;
int endJ = 0;

int n = 0;
int m = 0;

char a[1001][1001];

queue <pair <int, int>> coordinates;
int distanceForEachCoordinate[1001][1001];
char prevMoveForEachCoordinate[1001][1001];

// U, L, R, D
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

bool check(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '#';
}
void printPaths() {
    //go by distance and keep iterating until one of the coordiantes is the end or you cannot progress more

    memset(distanceForEachCoordinate, -1, sizeof(distanceForEachCoordinate));
    distanceForEachCoordinate[startI][startJ] = 0;



    while (!coordinates.empty()) { //while we can still get to the end
        int x = coordinates.front().first;
        int y = coordinates.front().second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            //(nx, ny)
            if (check(nx, ny) && distanceForEachCoordinate[nx][ny] == -1) {
                ....
            }
        }


        if (x + 1 <= n && distanceForEachCoordinate[x + 1][y] == -1 && a[x + 1][y] != '#') {
            coordinates.push({x + 1, y});
            distanceForEachCoordinate[x + 1][y] = distanceForEachCoordinate[x][y] + 1;
            prevMoveForEachCoordinate[x + 1][y] = 'D';
        }
        if (x - 1 > 0 && distanceForEachCoordinate[x - 1][y] == -1 && a[x - 1][y] != '#') {
            coordinates.push({x - 1, y});
            distanceForEachCoordinate[x - 1][y] = distanceForEachCoordinate[x][y] + 1;
            prevMoveForEachCoordinate[x - 1][y] = 'U';
        }
        if (y + 1 <= m && distanceForEachCoordinate[x][y + 1] == -1 && a[x][y + 1] != '#') {
            coordinates.push({x, y + 1});
            distanceForEachCoordinate[x][y + 1] = distanceForEachCoordinate[x][y] + 1;
            prevMoveForEachCoordinate[x][y + 1] = 'R';
        }
        if (y - 1 > 0 && distanceForEachCoordinate[x][y - 1] == -1 && a[x][y - 1] != '#') {
            coordinates.push({x, y - 1});
            distanceForEachCoordinate[x][y - 1] = distanceForEachCoordinate[x][y] + 1;
            prevMoveForEachCoordinate[x][y - 1] = 'L';
        }

        coordinates.pop();
    }

    if (distanceForEachCoordinate[endI][endJ] != -1) {
        cout << "YES" << endl;
        vector <char> pathToEnd;
        int i = endI;
        int j = endJ;
        while (i != startI || j != startJ) {
            pathToEnd.push_back(prevMoveForEachCoordinate[i][j]);

            if (prevMoveForEachCoordinate[i][j] == 'D') {
                i -= 1;
            } else if (prevMoveForEachCoordinate[i][j] == 'U') {
                i += 1;
            } else if (prevMoveForEachCoordinate[i][j] == 'L') {
                j += 1;
            } else {
                j -= 1;
            }
        }

        cout << distanceForEachCoordinate[endI][endJ] << endl;

        reverse(pathToEnd.begin(), pathToEnd.end());
        for (auto itr : pathToEnd) {
            cout << itr;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

}


int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];

            if (a[i][j] == 'A') {
                startI = i;
                startJ = j;
                coordinates.push({i, j});
            }
            if (a[i][j] == 'B') {
                endI = i;
                endJ = j;
            }

        }
    }
    printPaths();
    return 0;
}