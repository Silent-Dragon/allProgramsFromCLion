#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = (int)300;
const int modulo = (int)1e9 + 7;
int t, n, cnt;
char prevChar;

void checkStatusOfRowsAndColumns(int statusOfColumns[n], int statusOfRows[n], char **matrix) {

    //for rows
    for (int i = 0; i < n; i++) {
        cnt = 0;
        prevChar = '.';
        for (int j = 0; j < n; j++) {
            //if we have an X or O and previous is X or O, we increase counter
            if (matrix[i][j] != '.' && prevChar == matrix[i][j]) {
                cnt++;
            } else {
                cnt = 0;
                prevChar = matrix[i][j];
            }

            if (cnt >= 3) {
                statusOfRows[i] = 1;
                break;
            }
        }

        if (!statusOfRows[i]) {
            statusOfRows[i] = 0; //we do not have a winning configuration, WHICH IS GOOD
        }
    }

    //for columns
    for (int j = 0; j < n; j++) {
        cnt = 0;
        prevChar = '.';
        for (int i = 0; i < n; i++) {
            //if we have an X or O and previous is X or O, we increase counter
            if (matrix[i][j] != '.' && prevChar == matrix[i][j]) {
                cnt++;
            } else {
                cnt = 0;
                prevChar = matrix[i][j];
            }

            if (cnt >= 3) {
                statusOfColumns[j] = 1;
                break;
            }
        }

        if (!statusOfColumns[j]) {
            statusOfColumns[j] = 0; //not winning SO GOOD
        }
    }
}

int main() {
    cin >> t;

    //going through test cases
    for (int i = 1; i <= t; i++) {
        cin >> n;

        int statusOfRows[n]; //0 for winning, 1 for draw
        int statusOfColumns[n]; //0 for winning, 1 for draw

        char matrix[n][n];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> matrix[j][k];
            }
        }

        checkStatusOfRowsAndColumns(statusOfColumns, statusOfRows, matrix);
    }


    return 0;
}