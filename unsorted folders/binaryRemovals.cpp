/* Constructive Algorithms Template
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5; //max n we can have
int n, tests, t, s;

void customSort(string a) {
    //HERE YOU NEED TO SORT THIS ARRAY WITH THE CUSTOM SORT REQUIRED
    //e.g. sort in reverse order

    for (int i = 0; i < n; i++) {
        //this is the splitting point
        int prev = 0;
        bool isPossible = true;
        for (int j = 0; j < n; j++) {
            if (j < i) {
                if (a[j] == '1' && prev != 0) {
                    isPossible = false;
                    break;
                }

                if (a[j] == '1') {
                    prev = 1;
                } else {
                    prev = 0;
                }
            } else {
                if (a[j] == '0' && prev != 0) {
                    isPossible = false;
                    break;
                }

                if (a[j] == '0') {
                    prev = 1;
                } else {
                    prev = 0;
                }
            }
        }

        if (isPossible) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {

    cin >> tests;
    for (int t = 0; t < tests; t++) {
        //START OF INPUT
        string a; //sequence

        cin >> a;

        n = a.size();
        //END OF INPUT

        //CUSTOM SORT START
        customSort(a);
        //CUSTOM SORT END

        //OUTPUT START
        //OUTPUT END
    }

    return 0;
}