#include <iostream>

using namespace std;

int main() {
    long long int mod = 1e9 + 7;

    int n = 0;
    cin >> n;

    char a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    long long int count[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count[i][j] = 0;
        }
    }

    if (a[0][0] != '*') {
        count[0][0] = 1;
    }

    //////////////////////////////////////

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != '*') {
                if (i - 1 >= 0) {
                    count[i][j] += count[i - 1][j];
                    count[i][j] %= mod;
                }

                if (j - 1 >= 0) {
                    count[i][j] += count[i][j - 1];
                    count[i][j] %= mod;
                }

            }
        }
    }

    cout << count[n - 1][n - 1];
    return 0;
}
