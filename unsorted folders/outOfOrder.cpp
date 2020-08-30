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
    freopen ("outofplace.in", "r", stdin);
    freopen ("outofplace.out", "w", stdout);

    int n;
    int oddCow = -1;
    int swaps = 0;

    cin >> n;

    int order[n];

    //Here I get the cows in original order
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }

    //Here I complete step 1 and find the odd cow
    for (int i = 0; i < n; i++) {
        vector <int> a;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                a.push_back(order[j]);
            }
        }
        bool sorted = 1;
        for (int j = 1; j < a.size(); j++) {
            if (a[j] < a[j - 1]) {
                sorted = 0;
            }
        }
        if (sorted) {
            oddCow = i;
        }
    }
    if (oddCow == -1) {
        // array is sorted
        cout << swaps;
        return 0;
    }

    if (oddCow != 0) {
        // how would you know that now oddCow is in the right position
        while (oddCow != 0 && order[oddCow - 1] > order[oddCow]) {
            // oddCow = 0
            // order[oddCow - 1] > order[oddCow] && oddCow != 0
            for (int i = 0; i < oddCow; i++) {
                if (order[i] == order[oddCow - 1]) {
                    swap(order[oddCow], order[i]);
                    swaps++;
                    oddCow = i;
                    break;
                }
            }
        }
    }
    else {
        while (oddCow != n - 1 && order[oddCow + 1] < order[oddCow]) {
            // oddCow = 0
            // |
            // (6) 5 5 <-

            // order[oddCow] > order[oddCow + 1]
            for (int i = n - 1; i > oddCow; i--) {
                if (order[i] == order[oddCow + 1]) {
                    swap(order[oddCow], order[i]);
                    swaps++;
                    oddCow = i;
                    break;
                }
            }
        }
    }

    cout << swaps;

}