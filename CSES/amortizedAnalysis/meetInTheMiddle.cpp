#include <iostream>
#include <iterator>

using namespace std;

const int N = (int)2e5 + 7;
int n, sum;
int cnt = 0;
int a[N];

void twoPointers() { //Two pointer technique to find pairs which create a sum we are looking for in O(N)
    int pointer1 = 0; //first pointer
    int pointer2 = n - 1; //second pointer

    while (pointer1 < pointer2) {
        if (a[pointer1] + a[pointer2] == sum) {
            cnt++; //we were able to find the sum we were looking for
        ///TODO: find a way to continue from here in order to find MORE sums
        } else if (a[pointer1] + a[pointer2] < sum) {
            pointer1++; //we increase first pointer since we need a bigger sum
        } else {
            pointer2--; //we decrease second pointer since we need a smaller sum
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

/// Input
    cin >> n >> sum;
    for (int i = 0; i < n; i++) {
         cin >> a[i];
    }

/// Method
    twoPointers();
    cout << cnt << endl;
}