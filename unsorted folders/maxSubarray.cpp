#include <iostream>
#include <algorithm>

using namespace std;

long long int maximumSum = 0;
long long int sum = 0;
long long int n = 0;

int main() {
    cin >> n;

    long long int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    for (int i = 0; i < n; i++) {
        sum = max(array[i], sum + array[i]);
        maximumSum = max(maximumSum, sum);
    }
    if (sum < 0) {
        cout << sum << endl;
    } else {
        cout << maximumSum << endl;
    }

    return 0;
}
