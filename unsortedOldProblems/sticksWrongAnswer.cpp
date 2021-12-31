#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0;
map <int, int> sticks;
int modeLengthValue = 0;
int modeLengthKey = 0;
int totalDifference = 0;

int main() {
    freopen("in.txt", "r", stdin);

    cin >> n;

    int stickLengths[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> stickLengths[i];
    }

    for (int i = 0; i < n; i++) {
        sticks[stickLengths[i]] += 1;
        if (sticks[stickLengths[i]] >= modeLengthValue) {
            modeLengthValue = sticks[stickLengths[i]];
            modeLengthKey = stickLengths[i];
        }
    }

    for (unsigned int i = 0; i < sticks.size(); i++) {
        totalDifference += abs(modeLengthKey - stickLengths[i]);
    }

    cout << totalDifference << endl;

    return 0;
}
