#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n = 0; //size of our sequence
int k = 0; //size of sliding window
int median = 0;

multiset <int> firstHalf;
multiset <int> secondHalf;
multiset <int>::iterator pointer1;
multiset <int>::iterator pointer2;


void balance_multisets() {
/*
    k = 3
    2 1
    1 2
*/
    while (secondHalf.size() > 0 && firstHalf.size() > 0 && *firstHalf.rbegin() > *secondHalf.begin()) {
        if (firstHalf.size() >= secondHalf.size()) {
            secondHalf.insert(*firstHalf.rbegin());
            firstHalf.erase(--firstHalf.end());
        } else {
            firstHalf.insert(*secondHalf.begin());
            secondHalf.erase(secondHalf.begin());
        }
    }
    while (firstHalf.size() < secondHalf.size()) {
        firstHalf.insert(*secondHalf.begin());
        secondHalf.erase(secondHalf.begin());
    }
/*
    int x = 5;
    cout << x--; // 5
    cout << --x; // 4

    --firstHalf.end() != firstHalf.end()--
    firstHalf.rbegin()
*/

// [1, 2, 3, 4] [0, 7, 8, 10, 11]
}
void insert(int x) {
    secondHalf.insert(x);
    balance_multisets();
}
void erase(int x) {
    if (firstHalf.find(x) != firstHalf.end()) {
        firstHalf.erase(firstHalf.find(x));
    }
    else {
        secondHalf.erase(secondHalf.find(x));
    }
    balance_multisets();
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int a[n+ 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < k) {
            insert(a[i]);
        }
        /*
        if (i < k / 2) {
            firstHalf.insert(a[i]);
        } else if (i > k / 2 && i < k) {
            secondHalf.insert(a[i]);
        } else if (i == k / 2) {
            secondHalf.insert(a[i]);
        }
        */
    }

    for (int i = 0; i < n - k + 1; i++) {
        /*
            k = 3
            2 1

            k % 2 == 0 *firstHalf.rbegin()
            else *secondHalf.begin()
        */
        cout << *firstHalf.rbegin() << " ";

        //we need to erase the oldest number which will be the number with value i - 1
        /*
        if (a[i + k] > median) {
            firstHalf.insert(median);

            secondHalf.remove(median);
            secondHalf.insert(a[i + 4]);
        } else if (a[i + k] < median) {
            firstHalf.insert(a[i + 4]);
        } else {
            secondHalf.insert(a[i + 4]);
        }*/
        erase(a[i]);
        insert(a[i + k]);
    }


    return 0;
}
