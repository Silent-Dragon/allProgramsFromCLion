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
#include <unordered_map>

using namespace std;

long long int maxLength;

int main() {
    long long int n = 0;
    cin >> n;

    long long int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    //i can store my lists in a map with the index being the list number
    //<vector <int>> lists[1000000000];

    //I only need to store the last number of my list and its length
    unordered_map <int, int> lists; //index is last number and value is length

    int maxLength = 1;

    lists[a[1]] = 1;

    for (int i = 1; i <= n; i++) {
        //cout << "Entered loop with i as " << i << endl;

        int l = 1;
        int r = i - 1;
        int positionOfListToAddOnTo = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            cout << "l " << l << " r " << r << " and m " << m << endl;
            if (a[m] < a[i]) {
                cout << "The number " << lists[a[m]] << " works for " << a[i] << endl;
                positionOfListToAddOnTo = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (positionOfListToAddOnTo == 0) {
            //we were not able to find a list to add on to
            cout << "No match for number " << a[i] << " in place " << i << endl;
            lists[a[i]] = 1;
        } else {
            cout << "Match for number " << a[i] << " in place " << i << endl;
            lists[a[i]] = lists[a[positionOfListToAddOnTo]] + 1;
        }

        if (lists[a[i]] > maxLength) {
            maxLength = lists[a[i]];
        }
    }

    cout << maxLength << endl;
    return 0;
}

/*
 * What if save lists as we go?
 *
 */