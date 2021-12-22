#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

long long int n = 0;
long long int target = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> target;

    vector <int> numbers;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int itr = 0; itr < numbers.size(); itr++) {
        int target2 = target - numbers[itr];

        long long int l = itr + 1;
        long long int r = numbers.size() - 1;
        long long int m;
        long long int ans = -1;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (numbers[m] > target2) {
                r = m - 1;
            } else {
                ans = m;
                l = m + 1;
            }
        }

        if (ans != -1 && numbers[ans] == target2) {
            cout << "[" << itr + 1 << "," << ans + 1 << "]";
            //return {itr + 1, m + 1};
        }
    }

    return 0;
}