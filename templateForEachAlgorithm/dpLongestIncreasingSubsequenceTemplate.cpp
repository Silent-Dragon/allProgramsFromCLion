#include <iostream>
#include <vector>

using namespace std;

long long int n;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

///Input
    cin >> n; //size of the input array
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

///Method
    vector <int> dp;
    dp.push_back(a[0]); //before we start searching the answer for the subsequence with length of 1 is the first place in the array
    for (int i = 1; i < n; i++) {
        long lowerBoundPosition = (lower_bound(dp.begin(), dp.end(), a[i])) - dp.begin(); //this gives the
        //position for the lower bound search result

        if (lowerBoundPosition != dp.size()) {
            dp[lowerBoundPosition] = a[i]; //if there is an element before our current value that is larger than the
            //current value, we replace the element before our current value with our current value in the dp vector
            //where our final list/answer is stored
        } else {
            dp.push_back(a[i]); //if there is no element before our current element that is larger than the current
            //value, we just add the current value to the dp vector as it will be the next value in our final list/answer
        }
    }

/// Output
    cout << dp.size() << endl;
    return 0;
}