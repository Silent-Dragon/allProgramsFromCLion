#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
       freopen("cowsignal.in", "r", stdin);
       freopen("cowsignal.out", "w", stdout);
       // freopen("in.txt", "r", stdin);

        int r, c, k;
        cin >> r >> c >> k;

        for (int i = 0; i < r; i++) {
            // get the next row to generate k copies of
            string currRow;
            //getline(cin, currRow);
            cin >> currRow;

            // we will generate the same row K times
            for (int internalRow = 0; internalRow < k; internalRow++) {
                // loop over each character
                for (int j = 0; j < c; j++) {
                    // and print it k times
                    for (int a = 0; a < k; a++) {
                        cout << currRow[j];
                    }
                }
                // we need to print a new line to indicate that we need to go to the next row
                cout << endl;
            }
        }

       return 0;
}
