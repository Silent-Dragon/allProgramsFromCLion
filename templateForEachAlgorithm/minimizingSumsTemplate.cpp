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

long long int n = 0;
long double ans = 0;
long double median = 0;
long long int middle1 = 0;
long long int middle2 = 0;

vector <int> lengths;

int main() {
    //freopen("in.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m = 0;
        cin >> m;
        lengths.push_back(m);
    }

    sort(lengths.begin(), lengths.end());

    if (n % 2 == 0) { //even
        middle1 = lengths[n / 2];
        middle2 = lengths[n / 2 - 1];
        median = (middle1 + middle2) / 2; //calculating mean to find total median
    } else { //odd
        median = lengths[n / 2];
    }

    for (int i = 0; i < n; i++) {
        ans += abs(median - lengths[i]);
    }

    cout << (long long)ans << endl;

    return 0;
}