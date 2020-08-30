#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

long long int n = 0; //size of our sequence
long long int x = 0; //desired number
long long int temp = 0; //temp position
long long int delta = 0; //number needed
unordered_map <int, int> lastPositionOfNumber; //last position of every number

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lastPositionOfNumber.max_load_factor(0.25);
    lastPositionOfNumber.reserve(n * 2);

    cin >> n >> x;

    int a[n]; //sequence of numbers
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        lastPositionOfNumber[a[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            delta = x - a[i] - a[j];
            if (delta <= 0) {
                continue;
            }

            if (lastPositionOfNumber.count(delta)) {
                temp = lastPositionOfNumber[delta];
                if (temp != i + 1 && temp != j + 1) {
                    cout << i + 1 << " " << temp << " " << j + 1 << endl;
                    exit(0);
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
