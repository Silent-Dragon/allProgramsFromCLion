#include <iostream>

using namespace std;

long long int x = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x;

    if (x == 0) {
        cout << 0;
    } else {
        long long int l = 1;
        long long int r = x;

        while (l <= r) {
            long long int mid = (l + r) / 2;

            if (mid * mid > x) {
                r = mid - 1;
            } else {
                if (mid + 1 > x / (mid + 1)) {
                    cout << mid << endl;
                    break;
                }
                l = mid + 1;
            }
        }
    }

    return 0;
}