/* Constructive Algorithms Template
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5; //max n we can have
int n, testCases, minVal, ans, sum;

int main() {
    cin >> testCases;

    for (int t = 0; t < testCases; t++) {
        //START OF INPUT
        cin >> n; //length of sequence

        int costs[n]; //sequence
        for (int i = 0; i < n; i++) {
            cin >> costs[i];
            sum += costs[i];
        }
        //END OF INPUT

        //SOLUTION START
        for (int k = 0; k < n; k++) {
            minVal = min(minVal, costs[k]);
            ans = min(minVal * (n - k + 1) + (sum - minVal), ans);
        }
        //SOLUTION END

        //OUTPUT START
        cout << ans << endl;
        //OUTPUT END
    }

    return 0;
}