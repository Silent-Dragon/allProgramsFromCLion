#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long long int n = 0;
long double ans = 0;
long double median = 0;

vector <int> stickLengths;

int main() {
    //freopen("in.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m = 0;
        cin >> m;
        stickLengths.push_back(m);
    }

    sort(stickLengths.begin(), stickLengths.end());
    median = stickLengths[n / 2]; //median for both odd and even cases is n / 2

    for (int i = 0; i < n; i++) {
        ans += abs(median - stickLengths[i]);
    }

    cout << (long long)ans << endl;

    return 0;
}
