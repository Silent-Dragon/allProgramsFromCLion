#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long int n = 0; //number of cubes
long long int noTowers = 0;
multiset <int> towers;
int main() {
    cin >> n;

    int cubes[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
    }

    for (int i = 0; i < n; i++) {
        auto oldTowerTop = towers.upper_bound(cubes[i]);

        if (oldTowerTop == towers.end()) {
            noTowers++;
        } else {
            towers.erase(oldTowerTop);
        }
        towers.insert(cubes[i]);
    }

    cout << noTowers << endl;
    //or print size of multiset which has number of towers

    return 0;
}
