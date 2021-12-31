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

int connectedComponents;

int matrix[N][N];

int visited[N][N];
//int prevMoveForEachCoordinate[N][N]; If you want to print the path, then save each coordinate you go to and then print the path backwards

void DFS(int x, int y) {
    if (matrix[x][y] == 0) {
        return;
    }

    visited[x][y] = 1;
    if (x + 1 < n && visited[x + 1][y] == -1) {
        dfs(x + 1, y);
    }
    if (x - 1 >= 0 && visited[x - 1][y] == -1) {
        dfs(x - 1, y);
    }
    if (y + 1 < m && visited[x][y + 1] == -1) {
        dfs(x, y + 1);
    }
    if (y - 1 >= 0 && visited[x][y - 1] == -1) {
        dfs(x, y - 1);
    }
}


int main() {
    cin >> n >> m;

    //THERE ARE OBSTACLES INDICATED BY A 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == -1 && matrix[i][j] != 0) {
                DFS(i, j);
                connectedComponents++;
            }
        }
    }

    cout << connectedComponents << endl;

    return 0;
}


/*
 *
 *
 *
 *
 * Graph (number of connected components since the graph may have several groups)
 * Matrix (number of connected components with not every coordinate being a place you can go to)
 *
 *
 *
 *
 *
 *
 *
 *
 */