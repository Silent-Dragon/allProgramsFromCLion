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
#include <utility>

using namespace std;

long long int n = 0; //size of our sequence
long long int x = 0; //desired number
long long int temp1 = 0; //temp1 position
long long int temp2 = 0; //temp2 position
long long int delta = 0; //number needed
map <int, pair<int, int>> lastPositionsOfNumbers; //last position of every number

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    int a[n]; //sequence of numbers
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            lastPositionsOfNumbers[a[i] + a[j]].first = i + 1;
            lastPositionsOfNumbers[a[i] + a[j]].second = j + 1;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            delta = x - a[i] - a[j];
            if (delta <= 0) {
                continue;
            }

            if (lastPositionsOfNumbers.count(delta)) {
                temp1 = lastPositionsOfNumbers[delta].first;
                temp2 = lastPositionsOfNumbers[delta].second;
                if (temp1 != i + 1 && temp1 != j + 1 && temp2 != i + 1 && temp2 != j + 1) {
                    cout << i + 1 << " " << temp1  << " " << temp2 << " " << j + 1;
                    exit(0);
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
