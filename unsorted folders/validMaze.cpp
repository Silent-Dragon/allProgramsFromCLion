#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
int t;
int r;
int c;
char M[20][20];
vector <int> exits;

bool isPath(int i, int j) {

    if (i == exits[2] && j == exits[3]) {
        return true;
    }

    // if (i == r - 1 || j == c - 1) {
    //     return false;
    // }

    if (i + 1 < r && M[i + 1][j] == '.') {
        M[i][j] = '#';
        if (isPath(i + 1, j)) return true; // true
    }

    if (j + 1 < c && M[i][j + 1] == '.') {
        M[i][j] = '#';
        if (isPath(i, j + 1)) return true; // true
    }

    if (i - 1 > 0 && M[i - 1][j] == '.') {
        M[i][j] = '#';
        if (isPath(i - 1, j)) return true; // false
    }

    if (j - 1 > 0 && M[i][j - 1] == '.') {
        M[i][j] = '#';
        if (isPath(i, j - 1)) return true; // true
    }

    return false;

}


bool isValidMaze() {
    int cnt = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j == 0 || i == 0 || j == c - 1 || i == r - 1) {
                if (M[i][j] == '.') {
                    cnt++;
                    exits.push_back(i);
                    exits.push_back(j);
                }
            }
        }
    }

    if (cnt != 2) {
        return false; // not a valid maze because there are more than two entry points
    }


    if (isPath(exits[0], exits[1])) {
        return true;
    } else {
        return false;
    }

}


int main() {
    freopen ("in.txt", "r", stdin);

    //cout << "Input number of test cases: ";
    cin >> t;
    // cout << endl;

    for (int a = 0; a < t; a++) {
        //cout << "Enter rows maze " << a << ": ";
        cin >> r;
        //  cout << "Enter columns for maze: ";
        cin >> c;
        //cout << endl;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                //cout << "Enter value for place " << i << ", " << j << " in Maze " << a << ": ";
                cin >> M[i][j];
                //  cout << endl;
            }
        }


        if (isValidMaze()) {
            cout << "valid";
        } else {
            cout << "invalid";
        }
        cout << endl;

        exits.clear();

    }

    //cout << endl;
}