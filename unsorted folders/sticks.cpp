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

long long int n = 0;
long long int mean = 0;
long long int sum = 0;
long long int ans = 0;
long long int valueAboveEqualDiff = 0;
long long int valueBelowDiff = 0;
vector <int> stickLengths;
std::vector<int>::iterator valueAboveOrEqual;
int valueBelow;

int main() {
 //   freopen("in.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m = 0;
        cin >> m;
        stickLengths.push_back(m);

        sum += stickLengths[i];
    }

    mean = sum/n;

    sort(stickLengths.begin(), stickLengths.end());
    //cout << "Mean: " << mean << endl;

    valueAboveOrEqual = lower_bound(stickLengths.begin(), stickLengths.end(), mean);

    if (mean != stickLengths[valueAboveOrEqual - stickLengths.begin()]) {

        int index = -1;
        std::vector<int>::iterator it;
        for (it = stickLengths.begin(); it < valueAboveOrEqual; it++) {
            index = distance(stickLengths.begin(), it);
          //  cout << "Index" << index << endl;
        }

        // the next line caused me issues --> why??
        // valueBelow = stickLengths[index];

        valueAboveEqualDiff = abs(mean - stickLengths[valueAboveOrEqual - stickLengths.begin()]);
        valueBelowDiff = abs(mean - stickLengths[index]);

        //cout << "valueAboveOrEqual points to: " << stickLengths[valueAboveOrEqual - stickLengths.begin()] << endl;
        //cout << "valueBelow points to: " << stickLengths[index] << endl;

        //cout << "Lower bound diff: " << valueAboveEqualDiff << endl;
        //cout << "valueBelow diff: " << valueBelowDiff << endl;

        //cout << "Lower bound: " << stickLengths[valueAboveOrEqual - stickLengths.begin()] << endl;
        //cout << "Upper bound: " << stickLengths[index] << endl;

        if (valueBelowDiff < valueAboveEqualDiff) { //if lower bound is better
            mean = stickLengths[valueAboveOrEqual - stickLengths.begin()];
        //    cout << "Mean after lower bound: " << mean << endl;
        } else { //if upper bound is better
            mean = stickLengths[index];
           // cout << "Mean after upper bound: " << mean << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        ans += abs(mean - stickLengths[i]);
       // cout << ans << " ";
    }
 //   cout << endl;

    cout << ans << endl;

    return 0;
}
