/* Constructive Algorithms Template
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e7; //max n we can have
int n, m, t;
int a[N], b[N];

void solve() {

    //INPUT START
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    //INPUT END

    //SOLUTION START
    int cntPos = 0;
    int cntNeg = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) {
            if (!cntPos) {
                cout << "NO" << endl;
                return;
            }
        } else if (b[i] < a[i]) {
            if (!cntNeg) {
                cout << "NO" << endl;
                return;
            }
        }

        if (a[i] == 1) {
            cntPos++;
        } else if (a[i] == -1) {
            cntNeg++;
        }
    }

    cout << "YES" << endl;
    //SOLUTION END
}

int main() {

    cin >> t;
    for (int test = 1; test <= t; test++) {
        solve();
    }

    return 0;
}