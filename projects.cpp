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

using namespace std;
/*
bool cmp(int x, int y) {
    return e[x] < e[y];
}
*/
long long int noProjects;
long long int maxReward;

int main() {
    cin >> noProjects;

    int startTimes[noProjects + 1];
    int endTimes[noProjects + 1];
    long long int rewards[noProjects + 1];

    long long int dp[noProjects + 1];
    long long int aggregatedReward[noProjects + 1];
    long long int maxAggregatedReward[noProjects + 1];

    map <pair <int, int>, int> sortingByEndAndStartTime;

    maxAggregatedReward[0] = 0;
    for (int i = 1; i <= noProjects; i++) {
        cin >> startTimes[i];
        cin >> endTimes[i];
        cin >> rewards[i];

        sortingByEndAndStartTime[{endTimes[i], i}] = i;

        dp[i] = 1;
        aggregatedReward[i] = rewards[i]; //because the minimum reward a project will have is it's current reward
        maxAggregatedReward[i] = 0;
    }

    int order[noProjects + 1];
    int ind = 0;
    for (auto itr = sortingByEndAndStartTime.begin(); itr != sortingByEndAndStartTime.end(); ++itr) {
        order[++ind] = itr->second;
        //cout << order[itr->second] << " ";
        //cout << itr->first.first << " " << itr->first.second << endl;
    }
    //cout << endl;

   // for (int i = 1; i <= noProjects; i++) {
        //cout << order[i] << " " << endTimes[order[i]] << endl;
   // }
    //cout << endl;

//    int n = sizeof(startTimes)/sizeof(startTimes[0]);
 //   sort(startTimes, startTimes + n, sortByStart(1, startTimes, endTimes, rewards));
/*
    while (1) {
        for (int i = 0; i < noProjects - 1; i++) {
            if (endTimes[i] > endTimes[i + 1]) {
                swap(startTimes[i], startTimes[i + 1]);
                swap(endTimes[i], endTimes[i + 1]);
                swap(rewards[i], rewards[i + 1]);
            } else if (endTimes[i] == endTimes[i + 1]) {
                if (startTimes[i] > startTimes[i + 1]) {
                    swap(startTimes[i], startTimes[i + 1]);
                    swap(endTimes[i], endTimes[i + 1]);
                    swap(rewards[i], rewards[i + 1]);
                }
            }
        }

        bool sorted = 1;
        for (int i = 0; i < noProjects - 1; i++) {
            if (endTimes[i] > endTimes[i + 1]) {
               sorted = 0;
            } else if (endTimes[i] == endTimes[i + 1]) {
                if (startTimes[i] > startTimes[i + 1]) {
                    sorted = 0;
                }
            }
        }
        if (sorted) {
            break;
        }
    }


    for (int i = 1; i <= noProjects; i++) {
        cout << startTimes[order[i]] << " ";
        cout << endTimes[order[i]] << " ";
        cout << rewards[order[i]] << " ";
        cout << endl;
    }

    for (int i = 1; i <= noProjects; i++) {
        for (int j = 1; j < i; j++) {
            if (endTimes[order[j]] < startTimes[order[i]]) {
                if (aggregatedReward[order[i]] < aggregatedReward[order[j]] + rewards[order[i]]) {
                    aggregatedReward[order[i]] = aggregatedReward[order[j]] + rewards[order[i]];
                }
            }
        }
        if (aggregatedReward[order[i]] > maxReward) {
            maxReward = aggregatedReward[order[i]];
        }
    }
        cout << maxReward << endl;
*/


    for (int i = 1; i <= noProjects;  i++) {
        int l = 1;
        int r = i - 1;
        int answer = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (endTimes[order[m]] < startTimes[order[i]]) {
                answer = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        aggregatedReward[order[i]] = maxAggregatedReward[answer] + rewards[order[i]];
        maxAggregatedReward[i] = max(maxAggregatedReward[i - 1], aggregatedReward[order[i]]);
    }

    cout << maxAggregatedReward[noProjects];

    return 0;
}

