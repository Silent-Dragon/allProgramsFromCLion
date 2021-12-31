/* Constructive Algorithms Template
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 105; //max n we can have
int n, m, t;
char a[N][N];


int main() {

    cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    cout << "W";
                } else {
                    cout << "B";
                }
            }
            cout << endl;
        }
    }

    return 0;
}