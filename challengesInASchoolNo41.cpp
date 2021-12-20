/* Constructive Algorithms Template
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5; //max n we can have
int n, k, cnt, cntForOne, maxSwaps;
int ans[n];

void customSort(int a[]) {
    //HERE YOU NEED TO SORT THIS ARRAY WITH THE CUSTOM SORT REQUIRED
    //e.g. sort in reverse order

    for (int i = 0; i < n; i++) {
       if (a[i] == 0) {
           cnt += cntForOne;
       } else {
           cntForOne++;
       }
    }

    if (k > cnt) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < k; i++) {
            if (cnt == 0) {
                cout << -1 << endl;
            } else {
                ans[i] = min(cnt - (k - 1), maxSwaps);

            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

}

int main() {

    //START OF INPUT
    cin >> n; //length of sequence
    cin >> k; //moves

    int a[n]; //sequence
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //END OF INPUT

    //CUSTOM SORT START
    customSort(a);
    //CUSTOM SORT END

    //OUTPUT START
    //OUTPUT END

    return 0;
}