#include<iostream>
#include<algorithm>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int a[1000], b[1000];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a,a + n);
        sort(b,b + n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        int times = 0;
        int ai = -1, bi = n;

        while (times < k) {
            ai++;
            bi--;
            if (a[ai] < b[bi]) {
                sum = sum + b[bi] - a[ai];
                times++;
            }

            if (ai == n - 1 && bi == 0) {
                times = k + 1;
            }
        }
        cout << sum << endl;
    }

}