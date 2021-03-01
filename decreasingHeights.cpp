#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

const int N = (int)1e5 + 7;

int a[N][N];
int n, m, cnt;
int visited[N][N];
//vector <int> route;


void printPaths(int i, int j) {
    if (visited[i][j]) {
        return;
    }

    if (i == n - 1 || j == m - 1) {
        cout << a[i][j] << endl;
        cnt++;
        return;
    }


    if (i + 1 < n && a[i + 1][j] == 0) {
        visited[i][j] = 1;
        printPaths(i + 1, j);
    }

    if (j + 1 < m && a[i][j + 1] == 0) {
        visited[i][j] = 1;
        printPaths(i, j + 1);
    }

    //This only works for 2 direction since the answer for each coordinate depends on the answer for next coordinates


}



int main() {
    freopen ("in.txt", "r", stdin);

    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    printPaths(0, 0);

    if (cnt == 0) {
        cout << "Impossible";
    } else {
        cout << cnt;
    }

    return 0;
}