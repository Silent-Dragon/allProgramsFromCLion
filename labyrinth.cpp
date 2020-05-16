#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

char a[1000][1000];
int shortestPathLength[1000][1000];
int n = 0;
int m = 0;
int startI = 0;
int startJ = 0;
int endI = 0;
int endJ = 0;
int cnt = 0;
//vector <int> route;

bool isLeftValid[1000][1000];
bool isRightValid[1000][1000];
bool isUpValid[1000][1000];
bool isDownValid[1000][1000];
bool isFullyExplored[1000][1000];

void printPaths(int i, int j) {
    if (i == endI && j == endJ) {
        cout << "Reached end with path length " << shortestPathLength[i][j] << endl;
        cnt++;
        return;
    }

    if (shortestPathLength[i][j] > shortestPathLength[endI][endJ]) {
        cout << "Path is too long" << endl;
        return;
    }

    if (a[i][j + 1] != '#') {
        isRightValid[i][j] = true;
    }

    if (a[i][j - 1] != '#') {
        isLeftValid[i][j] = true;
    }

    if (a[i + 1][j] != '#') {
        isDownValid[i][j] = true;
    }

    if (a[i - 1][j] != '#') {
        isUpValid[i][j] = true;
    }

    //going down
    if (i + 1 <= n && a[i + 1][j] != '#') {
        if (shortestPathLength[i + 1][j] > shortestPathLength[i][j] + 1) {
            shortestPathLength[i + 1][j] = shortestPathLength[i][j] + 1;
            cout << "Shortest path length for " << i + 1 << " " << j << " is " << shortestPathLength[i + 1][j] << endl;
            cout << "D" << endl << endl;
            printPaths(i + 1, j);
        }
    }

    //going right
    if (j + 1 <= m && a[i][j + 1] != '#') {
        if (shortestPathLength[i][j + 1] > shortestPathLength[i][j] + 1) {
            shortestPathLength[i][j + 1] = shortestPathLength[i][j] + 1;
            cout << "Shortest path length for " << i << " " << j + 1 << " is " << shortestPathLength[i][j + 1] << endl;
            cout << "R" << endl << endl;
            printPaths(i, j + 1);
        }
    }

    //going up
    if (i - 1 > 0 && a[i - 1][j] != '#') {
        if (shortestPathLength[i - 1][j] > shortestPathLength[i][j] + 1) {
            shortestPathLength[i - 1][j] = shortestPathLength[i][j] + 1;
            cout << "Shortest path length for " << i - 1 << " " << j << " is " << shortestPathLength[i - 1][j] << endl;
            cout << "U" << endl << endl;
            printPaths(i - 1, j);
        }
    }

    //going left
    if (j - 1 > 0 && a[i][j - 1] != '#') {
        if (shortestPathLength[i][j - 1] > shortestPathLength[i][j] + 1) {
            shortestPathLength[i][j - 1] = shortestPathLength[i][j] + 1;
            cout << "Shortest path length for " << i << " " << j - 1 << " is " << shortestPathLength[i][j - 1] << endl;
            cout << "L" << endl << endl;

            //we have checked all possible options for current position
            isFullyExplored[i][j] = true;

            printPaths(i, j - 1);
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            cout << a[i][j] << " ";

            shortestPathLength[i][j] = 1e6 + 1;

            if (a[i][j] == 'A') {
                startI = i;
                startJ = j;
            }

            if (a[i][j] == 'B') {
                endI = i;
                endJ = j;
            }
        }
        cout << endl;
    }
    cout << startI << " " << startJ << endl;
    cout << endI << " " << endJ << endl;

    shortestPathLength[startI][startJ] = 0;

    cout << "Input complete. Now going to function" << endl;
    printPaths(startI, startJ);

    if (cnt == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << shortestPathLength[endI][endJ] << endl;
    }
/*
 *
 * Logs for each position to check if they have a valid up/down/left/right
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << "For place " << i << " " << j << " :" << endl;
            if (isRightValid[i][j]) {
                cout << "Right is valid" << endl;
            } else {
                cout << "Right is not valid" << endl;
            }

            if (isLeftValid[i][j]) {
                cout << "Left is valid" << endl;
            } else {
                cout << "Left is not valid" << endl;
            }

            if (isDownValid[i][j]) {
                cout << "Down is valid" << endl;
            } else {
                cout << "Down is not valid" << endl;
            }

            if (isUpValid[i][j]) {
                cout << "Up is valid" << endl;
            } else {
                cout << "Up is not valid" << endl;
            }
            cout << endl;
        }
    }

*/
    return 0;
}