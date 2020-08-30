#include <iostream>

using namespace std;

int n;
int A[100000];

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    //freopen("in.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ans = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ans = i;
        } else {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}