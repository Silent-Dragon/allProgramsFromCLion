#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 1000;
const int modulo = (int)1e9 + 7;
char trygub[N] = "trygub";
int t, n;

int main() {
    cin >> t;

    //going through test cases
    for (int i = 1; i <= t; i++) {
        cin >> n;
        char originalSequence[N];
        int counterForTrygub = 0;
        int positionOfT = 0;

        for (int j = 0; j < n; j++) {
            cin >> originalSequence[j];

            if (originalSequence[j] == trygub[counterForTrygub] && originalSequence[j] == 't') {
                positionOfT = counterForTrygub;
                counterForTrygub++;
            } else if (originalSequence[j] == trygub[counterForTrygub]) {
                counterForTrygub++;
            }
        }

        if (counterForTrygub == 6) {
            originalSequence[positionOfT] = originalSequence[n - 1];
            originalSequence[n - 1] = 't';
        }

        for (int j = 0; j < n; j++) {
            cout << originalSequence[j];
        }
        cout << endl;
    }


    return 0;
}