#include <iostream>

using namespace std;

int n = 0;
long long int mod = 1e9 + 7;

int main() {

/// Input
    cin >> n;
    char matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

///Method
    long long int count[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count[i][j] = 0; //counting number of paths for a place [i][j] in the matrix by counting answer for previous squares
        }
    }

    if (matrix[0][0] != '*') {
        count[0][0] = 1; //marking traps
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != '*') { //only if there is no trap
                if (i - 1 >= 0) {
                    count[i][j] += count[i - 1][j]; //we set the answer for the current square to the answer of the
                    // previous square plus 1, as they all have 1 by default
                    count[i][j] %= mod; //take our answer by modulo
                }

                if (j - 1 >= 0) {
                    count[i][j] += count[i][j - 1]; //we set the answer for the current square to the answer of the
                    // previous square plus 1, as they all have 1 by default
                    count[i][j] %= mod; //take our answer by modulo
                }
            }
        }
    }

/// Output
    cout << count[n - 1][n - 1]; //print the answer for the bottom right corner
    return 0;
}