#include <iostream>
#include <algorithm>

using namespace std;

long long int maximumSum = -1e18;
long long int sum = 0;
long long int n = 0;
long long int a = 0;
long long int b = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;

    long long int array[n];
    long long int forwardSums[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];

        forwardSums[i] = array[i];
        if (i > 0) {
            forwardSums[i] += forwardSums[i - 1];
        }

       
    }
/*
    for (int i = 0; i < n; i++) {
        sum = max(array[i], sum + array[i]);
        maximumSum = max(maximumSum, sum);
    }
    */

    for (int i = 0; i < n; i++) {      
        for (int j = i + a - 1; j < min(i + b, n); j++) {
            if (i == 0) {
              maximumSum = max(maximumSum, forwardSums[j]);
            } else {
              maximumSum = max(maximumSum, forwardSums[j] - forwardSums[i - 1]);
            }
        }
    }

    cout << maximumSum;
    return 0;
}