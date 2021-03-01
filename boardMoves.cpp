#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

const int N = (int)1e5 + 7;

long long int n, t, cnt;

long long int ans(long long int currentN) {
    if (currentN - 2 > 0) {
        return 8 * (currentN / 2) * (currentN / 2) + ans(currentN - 2);
    } else {
        return 0;
    }
}



int main() {
    cin >> t;

    for (int test = 0; test < t; test++) {
        cin >> n;

        cout << ans(n) << endl;
    }

    return 0;
}