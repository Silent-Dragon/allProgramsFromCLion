#include <iostream>
#include <algorithm>

using namespace std;

long long int n = 0;
long long int ans = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

///Input
    cin >> n;
    long long int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

///Method
    sort(numbers, numbers + n); //sorting array so that we can go through it in numerical order

    long long int limit = 1;
    if (numbers[0] != 1) {
        ans = limit;
    } else {
        for (int i = 1; i < n; i++) {
            if (numbers[i] < limit + 2) {
                limit += numbers[i]; //we are able to use numbers[i] as it doesn't exceed the limit by more than 2
            } else {
                break; //we were unable to use numbers[i] and so can't generate a larger smallest sum
            }
        }

        ans = limit + 1; //answer is the limit + 1 as we can't generate a sum which is 1 more than the limit
    }

///Output
    cout << ans << endl;
    return 0;
}
