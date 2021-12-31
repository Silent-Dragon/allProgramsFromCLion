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

long long int n = 0; //applicants
long long int m = 0; //apartments
long long int k = 0; //maximum allowed difference
long long int cnt = 0; //counter of matched apartments

vector <int> actualSize;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    int desiredSize[n];
    for (int i = 0; i < n; i++) {
        cin >> desiredSize[i];
    }

    for (int i = 0; i < m; i++) {
        int a = 0;
        cin >> a;

        actualSize.push_back(a);
    }
    sort(actualSize.begin(), actualSize.end());


    for (int i = 0; i < n; i++) {
        if (actualSize.size() == 0) {
            continue;
        }

        vector<int>::iterator upperBoundPointer;
        upperBoundPointer = upper_bound(actualSize.begin(), actualSize.end(), desiredSize[i]);

        if (upperBoundPointer == actualSize.begin()) {
            if (*upperBoundPointer >= desiredSize[i] - k && *upperBoundPointer <= desiredSize[i] + k) {
                cnt++;
                actualSize.erase(upperBoundPointer);
            }
        } else if (upperBoundPointer == actualSize.end()) {
            upperBoundPointer--;
            if (*upperBoundPointer >= desiredSize[i] - k && *upperBoundPointer <= desiredSize[i] + k) {
                cnt++;
                actualSize.erase(upperBoundPointer);
            }
        } else {
            if (*upperBoundPointer >= desiredSize[i] - k && *upperBoundPointer <= desiredSize[i] + k) {
                cnt++;
                actualSize.erase(upperBoundPointer);
                break;
            }

            upperBoundPointer--;
            if (*upperBoundPointer >= desiredSize[i] - k && *upperBoundPointer <= desiredSize[i] + k) {
                cnt++;
                actualSize.erase(upperBoundPointer);
            }
        }

    }

    cout << cnt << endl;

    return 0;
}
