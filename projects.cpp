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

long long int noProjects;
long long int maxReward;

int main() {
    cin >> noProjects;

    int startTimes[noProjects + 1];
    int endTimes[noProjects + 1];
    long long int rewards[noProjects + 1];
    for (int i = 1; i <= noProjects; i++) {
        cin >> startTimes[i];
        cin >> endTimes[i];
        cin >> rewards[i];
    }
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
*/
    for (int i = 1; i <= noProjects; i++) {
        cout << startTimes[i] << " ";
        cout << endTimes[i] << " ";
        cout << rewards[i] << " ";
        cout << endl;
    }

    long long int dp[noProjects + 1];
    int aggregatedReward[noProjects + 1];
    for (int i = 1; i <= noProjects; i++) {
        dp[i] = 1;
        aggregatedReward[i] = 0;
    }
    int latestAddedReward = 0;

    int jAndiSequential = 1;
    for (int i = 2; i <= noProjects; i++) {
        if (jAndiSequential) {
            int j = i - 1;
        }
        //for (int j = i - 1; j < i; j++) {
            if (endTimes[j] < startTimes[i]) {
                jAndiSequential = 1;
                if (maxReward - latestAddedReward + rewards[i] > maxReward) {

                    if (maxReward - latestAddedReward + rewards[i] > maxReward) {
                    latestAddedReward = rewards[i];
                    aggregatedReward[i] = rewards[j] + rewards[i];
                } else {
                    latestAddedReward = 0;
                }
                //dp[i] = max(dp[i], dp[j]);
                //cout << "dp[i] is " << dp[i] << " and currentProjects are " << i << " and " << j << endl;
         //   }
            } else {
                jAndiSequential = 0;
            }

        if (aggregatedReward[i] > maxReward) {
            maxReward = aggregatedReward[i];
        }
    }

    cout << maxReward << endl;

    return 0;
}
