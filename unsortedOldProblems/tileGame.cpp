#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

int n, m;
char a[101][101];
int path[101][101];

//returns state of player 1
int state(int i, int j) {
    if (i == n && j == m) {
        path[i][j] = 0;
        return 0; //lose
    }

    if (j + 1 <= m && a[i][j + 1] != '#') {
        if (state(i, j + 1) == 0) {
            path[i][j] = 1;
            return 1; //win
        }
    }

    if (i + 1 <= n && a[i + 1][j] != '#') {
        if (state(i + 1, j) == 0) {
            path[i][j] = 1;
            return 1; //win
        }
    }

    path[i][j] = 0;
    return 0; //lose because you can't make a winning move
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

    if (state(1,1)) {
        cout << "Win" << endl;
    } else {
        cout << "Lose" << endl;
    }

    return 0;
}