/* Constructive Algorithms Template
 */
#define show(a) cerr << #a <<" -> "<< a <<"\n"

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5; //max n we can have
int n, tests, k1, k2, k3, k4, ans, ansForWhite, ansForBlack, w, b;

int main() {
    //START OF INPUT
    cin >> tests;

    for (int t = 0; t < tests; ++t) {
        cin >> n; //length of sequence

        cin >> k1 >> k2 >> w >> b;
//        cout << k1 << ' ' << k2 << endl;
        //END OF INPUTra

        //CUSTOM SORT START
        ans = w + b;

        if (k1 > k2) {
            swap(k1, k2);
        }
//        cout << k1 << ' ' << k2 << endl;
        ansForWhite = k1 + ((k2 - k1) / 2);

        k3 = n - k2;
        k4 = n - k1;

//        cout << k3 << ' ' << k4 << endl;
        ansForBlack = k3 + ((k4 - k3) / 2);
//        cout << ansForBlack << ' ' << ansForWhite << ' ' << ans << endl;
        if (ansForBlack + ansForWhite >= ans) {
            if (ansForWhite >= w && ansForBlack >= b) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }

     /*   cout << "k1: " << k1 << endl;
        cout << "k2: " << k2 << endl;
        cout << "k3: " << k3 << endl;
        cout << "k4: " << k4 << endl;
        cout << "ansForB: " << ansForBlack << endl;
        cout << "ansForW: " << ansForWhite << endl;

        show(ans);
       */ //CUSTOM SORT END

        //OUTPUT START

        //OUTPUT END
    }
    return 0;
}