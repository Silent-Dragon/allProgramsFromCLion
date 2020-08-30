#include <iostream>

using namespace std;

int n;
int S[101], T[101], B[101];
int start[1001], finish[1001];

int solve() {
    int bucketsNeeded = 0, b = 0;

    for (int t = 1; t <= 1000; t++) {

        if (start[t]) {
            b += B[start[t]];
        }

        bucketsNeeded = max(bucketsNeeded, b);

        if (finish[t]) {
            b -= B[finish[t]];
        }
    }

    return bucketsNeeded;
}

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    //freopen("in.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> S[i] >> T[i] >> B[i];

        start[S[i]] = i;
        finish[T[i]] = i;
    }

    cout << solve() << endl;

    return 0;
}