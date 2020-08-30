#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int a[1000][1000];
int n;
int m;
int cnt = 0;
//vector <int> route;


void printPaths(int i, int j) {

    if (i == n - 1 || j == m - 1) {
        //cout << a[i][j] << endl;
        cnt++;
        return;
    }


    if (i + 1 < n && a[i + 1][j] == 0) {
        printPaths(i + 1, j);
    }

    if (j + 1 < m && a[i][j + 1] == 0) {
        printPaths(i, j + 1);
    }


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