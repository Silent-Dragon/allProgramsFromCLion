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

bool cmp(int x, int y) {
    return e[x] < e[y];
}

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

    int n = sizeof(startTimes)/sizeof(startTimes[0]);
    sort(startTimes, startTimes + n, sortByStart(1, startTimes, endTimes, rewards));
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
        aggregatedReward[i] = rewards[i]; //because the minumum reward a project will have is it's current reward
    }
    int latestAddedReward = 0;



    for (int i = 1; i <= noProjects; i++) {
        for (int j = 1; j < i; j++) {
            if (endTimes[j] < startTimes[i]) {
                if (aggregatedReward[i] < aggregatedReward[j] + rewards[i]) {
                    aggregatedReward[i] = aggregatedReward[j] + rewards[i];
                }
            }
        }
        if (aggregatedReward[i] > maxReward) {
            maxReward = aggregatedReward[i];
        }
    }
        cout << maxReward << endl;

        return 0;
    }

