#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;

ll k, a[21][21];

void solve(ll i, ll j, ll n, ll x, ll sofar) {
    if (i == n && j == n) {
        if (sofar <= x) k++;
    } else if (i <= n && j <= n && sofar < x) {
        solve(i+1, j, n, x, sofar + a[i+1][j]);
        solve(i, j+1, n, x, sofar + a[i][j+1]);
    }
}

int main() {
    ll t, n, x;

    cin >> t;
    while (t--) {
        k = 0;
        memset(a, 0, sizeof(a));
        cin >> n >> x;

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        solve(1, 1, n, x, a[1][1]);
        cout << k << "\n";
    }
}