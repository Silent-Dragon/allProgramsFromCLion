#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

int n = 0;
int maxNumber = 0;
long long int sum = 0;
long long int timeTaken = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];

        //maxNumber = max(maxNumber, a[i]); SAME AS BELOW
        if (a[i] > maxNumber) {
            maxNumber = a[i];
        }
    }

    if (sum - maxNumber > maxNumber) {
        cout << sum;
    } else {
        cout << maxNumber * 2;
    }




    return 0;
}