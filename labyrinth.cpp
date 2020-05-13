#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

char a[1001][1001];
int shortestPathLength[1001][1001];
int n = 0;
int m = 0;
int startI = 0;
int startJ = 0;
int endI = 0;
int endJ = 0;
int cnt = 0;
//vector <int> route;

//vector <char> possibleDirections[1001][1001];

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
/*
    if (a[i][j + 1] != '#') {
        possibleDirections[i][j].push_back('R');
    }

    if (a[i][j - 1] != '#') {
        possibleDirections[i][j].push_back('L');
    }

    if (a[i + 1][j] != '#') {
        possibleDirections[i][j].push_back('D');
    }

    if (a[i - 1][j] != '#') {
        possibleDirections[i][j].push_back('U');
    }
*/
    if (i + 1 <= n && a[i + 1][j] != '#') {
        if (shortestPathLength[i + 1][j] > shortestPathLength[i][j] + 1) {
            shortestPathLength[i + 1][j] = shortestPathLength[i][j] + 1;
            cout << "Shortest path length for " << i + 1 << " " << j << " is " << shortestPathLength[i + 1][j] << endl;
            cout << "D" << endl << endl;
            printPaths(i + 1, j);
        }
    }

    if (j + 1 <= m && a[i][j + 1] != '#') {
        if (shortestPathLength[i][j + 1] > shortestPathLength[i][j] + 1) {
            shortestPathLength[i][j + 1] = shortestPathLength[i][j] + 1;
            cout << "Shortest path length for " << i << " " << j + 1 << " is " << shortestPathLength[i][j + 1] << endl;
            cout << "R" << endl << endl;
            printPaths(i, j + 1);
        }
    }

    if (i - 1 > 0 && a[i - 1][j] != '#') {
        if (shortestPathLength[i - 1][j] > shortestPathLength[i][j] + 1) {
            shortestPathLength[i - 1][j] = shortestPathLength[i][j] + 1;
            cout << "Shortest path length for " << i - 1 << " " << j << " is " << shortestPathLength[i - 1][j] << endl;
            cout << "U" << endl << endl;
            printPaths(i - 1, j);
        }
    }

    if (j - 1 > 0 && a[i][j - 1] != '#') {
        if (shortestPathLength[i][j - 1] > shortestPathLength[i][j] + 1) {
            shortestPathLength[i][j - 1] = shortestPathLength[i][j] + 1;
            cout << "Shortest path length for " << i << " " << j - 1 << " is " << shortestPathLength[i][j - 1] << endl;
            cout << "L" << endl << endl;
            printPaths(i, j - 1);
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
          //  cout << a[i][j] << " ";

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
       //cout << endl;
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


    return 0;
}