#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[101][101];
int cnt;

// n = number of rows
// m = number of columns
// a = matrix
// cnt = counter for number of connected components

void CC() {

    if (i == exits[2] && j == exits[3]) {
        return true;
    }

    if (i == r - 1 || j == c - 1) {
        return false;
    }


    if (i + 1 < r && M[i + 1][j] == '.') {
        isPath(i + 1, j);
    }

    if (j + 1 < c && M[i][j + 1] == '.') {
        isPath(i, j + 1);
    }

    if (i - 1 > 0 && M[i - 1][j] == '.') {
        isPath(i - 1, j);
    }

    if (j - 1 > 0 && M[i][j - 1] == '.') {
        isPath(i, j - 1);
    }

    return false;

}

int main() {
    cout << "Enter number of rows: ";
    cin >> n;
    cout << endl;

    cout << "Enter number of columns: ";
    cin >> m;
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter a # or . for place " << i << ", " << j << ": ";
            cin >> a[i][j];
            cout << endl;
        }
    }

    CC();
    cout << cnt;

    return 0;
}
