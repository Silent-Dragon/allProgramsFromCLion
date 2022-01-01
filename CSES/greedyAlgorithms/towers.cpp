#include <iostream>
#include <set>

using namespace std;

long long int n = 0;
long long int ans = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

///Input
    cin >> n;
    long long int cubes[n];
    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
    }

///Method
    multiset <long long int> towers;
    towers.insert(cubes[0]); //placing the first cube into an empty tower

    for (int i = 1; i < n; i++) {
        auto upperBoundResult = towers.upper_bound(cubes[i]);
        if (upperBoundResult != towers.end()) {
            towers.erase(upperBoundResult);
        }

        towers.insert(cubes[i]);
    }

    ans = towers.size();

///Output
    cout << ans << endl;
    return 0;
}
