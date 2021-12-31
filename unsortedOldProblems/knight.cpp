#include <iostream>
#include <vector>
using namespace std;

int a[1000][1000];
int n;
int m;
int cnt = 0;

void printPaths(int i, int j) {

    if (i == n - 1 || j == m - 1) {
        //cout << a[i][j] << endl;
        cnt++;
        return;
    }




    if (i + 1 < n && j + 2 < m) {
        printPaths(i + 1, j + 2);
    }

    if (j + 1 < m && i + 2 < n) {
        printPaths(i + 2, j + 1);
    }

}


int main() {
    cin >> n;
    cin >> m;


    printPaths(0, 0);

    cout << cnt;

    return 0;
}