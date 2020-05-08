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
    vector <long long int> lists; //index is length and value is smallest possible last number

    int maxLength = 1;

    for (int i = 1; i <= n; i++) {
        //cout << "Entered loop with i as " << i << endl;

        vector <long long int>::iterator positionOfListToAddOnTo;
        positionOfListToAddOnTo = lower_bound(lists.begin(), lists.end(), a[i]);

        if (positionOfListToAddOnTo == lists.end()) {
            //we were not able to find a list to add on to
           //cout << "No match for number " << a[i] << " in place " << i << endl;
            lists.push_back(a[i]);
        } else {
           // cout << "Match for number " << a[i] << " in place " << i << endl;
            *positionOfListToAddOnTo = min(*positionOfListToAddOnTo, a[i]);
        }
    }

    cout << lists.size() << endl;
    return 0;
}

/*
 * What if save lists as we go?
 *
 */