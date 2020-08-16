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

using namespace std;

int n, currentTime, cnt, timelines; //number of movies
multiset <pair <int, int>> startAndEndTimes; //Automatically sorted with multiset

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int start;
        int end;
        cin >> start >> end;

        startAndEndTimes.insert(make_pair(end, start));
    }

    //If we had just one person/timeline
    for (auto i = startAndEndTimes.begin(); i != startAndEndTimes.end(); i++) {
        if (i->second >= currentTime) {
            currentTime = i->first;
            cnt++;
        }

        if (startAndEndTimes.size() == 0) {
            break;
        }
    }

    cout << cnt << endl;

    //If we had multiple people/timelines...
    multiset <int> currentTimes;
    pair <int, int> startAndEndTimes2[n];
    n = 0;
    cnt = 0;
    timelines = 0;

    cin >> n >> timelines;

    for (int i = 0; i < n; i++) {
        cin >> startAndEndTimes2[i].second >> startAndEndTimes2[i].first;
    }
    sort(startAndEndTimes2, startAndEndTimes2 + n); //Need to sort since it's an array, not a multiset


    for (int i = 0; i < timelines; i++) {
        currentTimes.insert(0); //All timelines starting at 0
    }


    for (int i = 0; i < n; i++) {
        multiset<int>::iterator upperBoundResult;
        upperBoundResult = currentTimes.upper_bound(startAndEndTimes2[i].second);

        if (upperBoundResult != currentTimes.begin()) {
            upperBoundResult--;
            cnt++;
            currentTimes.erase(upperBoundResult);
            currentTimes.insert(startAndEndTimes2[i].first);

        }
    }


    cout << cnt << endl;


    return 0;
}
