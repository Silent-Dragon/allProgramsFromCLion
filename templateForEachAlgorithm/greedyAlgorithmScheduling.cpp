#include <iostream>
#include <map>
#include <utility>
#include <set>

using namespace std;

int n = 0; //number of events
int ans = 0; //events we attended
int currentTime = 0;

multiset <pair <int, int>> startAndEndTimes;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

/// Input
    cin >> n;
    for (int i = 0; i < n; i++) {
        int start;
        int end;
        cin >> start >> end;

        startAndEndTimes.insert(make_pair(end, start));
    }

/// Method
    for (auto i = startAndEndTimes.begin(); i != startAndEndTimes.end(); i++) {
        if (i->second >= currentTime) {
            currentTime = i->first;
            //startAndEndTimes.erase(i);
            //will not affect since we do not go backwards
            ans++;
        }

        if (startAndEndTimes.empty()) {
            break;
        }
    }

/// Output
    cout << ans << endl;
    return 0;
}
