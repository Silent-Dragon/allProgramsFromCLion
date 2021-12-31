#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int cost[21][21];
int m;
int n;


int minCost() {
    int sum;

    int tc[n][m];

    tc[0][0] = cost[0][0];

    // answer for 1st column
    for (int i = 1; i < n; i++){
        tc[i][0] = tc[i - 1][0] + cost[i][0];
    }
    // answer for 1st row
    for (int j = 1; j < m; j++) {
        tc[0][j] = tc[0][j - 1] + cost[0][j];
        /*
            j = 0
            tc[0][j] = tc[0][j - 1] + cost[0][j]
        */
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // answer for cell (i, j)
            /*  (i, j) = (3, 0)
                (i - 1, j) = (2, 0)
                (i, j - 1) -> (i, j)
            */
            // tc[i - 1][j] // only if (i - 1, j) is a valid cell
            // tc[i][j - 1] // only if (i, j - 1) is a valid cell
            /*
                0 <= i < n
                0 <= j < m
            */
            tc[i][j] = max(tc[i - 1][j], tc[i][j - 1]) + cost[i][j];
        }
    }
    // (m, n) -> (n, m)
    return tc[n - 1][m - 1];
}


int main() {
    freopen ("in.txt", "r", stdin);

    // cout << "Enter the number of rows: ";
    cin >> n;
    //cout << endl;

    // cout << "Enter number of columns: ";
    cin >> m;
    //cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //    cout << "Enter fine for place " << i << ", " << j << " in the table: ";
            cin >> cost[i][j];
        }
    }

    cout << minCost();


}
