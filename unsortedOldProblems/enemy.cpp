#include <iostream>
using namespace std;

int t = 0;
int n = 0;
int cnt = 0;
int ans = 0;
int rowIterator = 0;
int columnIterator = 0;

int main() {
    //code
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n;
        int a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }


        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != '.') {
                    cnt++;
                }
            }
        }

        if (cnt >= 3) {
            ans += cnt;
        }
        cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (a[i][j] != '.') {
                    cnt++;
                }
            }
        }

        if (cnt >= 3) {
            ans += cnt;
        }
        cnt = 0;

        rowIterator = 0;
        columnIterator = 0;
        while (rowIterator < n - 2) {
            for (int i = rowIterator; i < n; i++) {
                if (a[i][columnIterator] != '.') {
                    cnt++;
                }

                columnIterator++;
            }

            if (cnt >= 3) {
                ans += cnt;
            }
            cnt = 0;
        }

        rowIterator = 0;
        columnIterator = 0;
        while (columnIterator < n - 2) {
            for (int j = columnIterator; j < n; j++) {
                if (a[rowIterator][j] != '.') {
                    cnt++;
                }

                rowIterator++;
            }

            if (cnt >= 3) {
                ans += cnt;
            }
            cnt = 0;
        }

        cout << cnt << endl;

    }

    return 0;
}