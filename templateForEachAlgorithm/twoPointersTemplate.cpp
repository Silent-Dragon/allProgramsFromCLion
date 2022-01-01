#include <iostream>
#include <iterator>

using namespace std;

const int N = (int)2e5 + 7;
int n, sum, ansPointer1, ansPointer2;
int a[N];

int twoPointers() { //Two pointer technique to find pairs which create a sum we are looking for in O(N)
    int pointer1 = 0; //first pointer
    int pointer2 = n - 1; //second pointer

    while (pointer1 < pointer2) {
        if (a[pointer1] + a[pointer2] == sum) {
            ansPointer1 = pointer1;
            ansPointer2 = pointer2;
            return 1; //we were able to find the sum we were looking for
        } else if (a[pointer1] + a[pointer2] < sum) {
            pointer1++; //we increase first pointer since we need a bigger sum
        } else {
            pointer2--; //we decrease second pointer since we need a smaller sum
        }
    }

    return 0; //we could not make the sum
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Please enter size of array: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Please enter array in place " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "Please enter sum we want to make: ";
    cin >> sum;

    if (twoPointers()) {
        cout << "We were able to make sum " << sum << " by using numbers " << a[ansPointer1] << " and " << a[ansPointer2];
    } else {
        cout << "We were not able to make sum " << sum;
    }

    cout << endl;
}