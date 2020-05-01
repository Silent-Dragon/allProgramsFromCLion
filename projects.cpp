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
struct projects {
    int start, end, reward;
};
*/
int startTimes[2 * 1000000];
int endTimes[2 * 1000000];
int rewards[2 * 1000000];

//MAP for usedPaths
long long int noProjects;
long long int maxReward;
//projects a[1000000];

long long int buildPaths(long long int currentReward, long long int projectNumber) {
   // cout << "Before changes " << endl;
    //usedPaths[currentPath] = 1;

//    aggregatedReward[currentPath] = previousPathReward + rewards[projectNumber];
    if (projectNumber != noProjects - 1) {
        for (int i = projectNumber + 1; i < noProjects; i++) {
            if (endTimes[projectNumber] < startTimes[i]) {
/*
                long long int newPath = currentPath;
                newPath *= 10;
                newPath += i;
*/
                long long int newReward;
                newReward = currentReward + rewards[i];

                buildPaths(newReward, i);
            }
        }
    }

   // cout << "currentProject start: " << startTimes[projectNumber] << endl;
 //   cout << "currentProject end: " << endTimes[projectNumber] << endl;
 //   cout << "currentProject reward: " << rewards[projectNumber] << endl;

 //   cout << "Reached end of loop with path " << currentPath << endl;
    if (currentReward > maxReward) {
        maxReward = currentReward;
    }

    return 0;
}


int main() {
    cin >> noProjects;
   // long long int aggregatedReward[noProjects * ((1 + noProjects) / 2)];

    for (int i = 0; i < noProjects; i++) {
        //store start end and reward
        cin >> startTimes[i];
        cin >> endTimes[i];
        cin >> rewards[i];
    }

    while (1) {
        for (int i = 0; i < noProjects - 1; i++) {
            if (startTimes[i] > startTimes[i + 1]) {
                swap(startTimes[i], startTimes[i + 1]);
                swap(endTimes[i], endTimes[i + 1]);
                swap(rewards[i], rewards[i + 1]);
            } else if (startTimes[i] == startTimes[i + 1]) {
                if (endTimes[i] > endTimes[i + 1]) {
                    swap(startTimes[i], startTimes[i + 1]);
                    swap(endTimes[i], endTimes[i + 1]);
                    swap(rewards[i], rewards[i + 1]);
                }
            }
        }

        bool sorted = 1;
        for (int i = 0; i < noProjects - 1; i++) {
            if (startTimes[i] > startTimes[i + 1]) {
                sorted = 0;
            } else if (startTimes[i] == startTimes[i + 1]) {
                if (endTimes[i] > endTimes[i + 1]) {
                    sorted = 0;
                }
            }
        }
        if (sorted) {
            break;
        }
    }

    for (int i = 0; i < noProjects; i++) {
      //  cout << "Loop " << i << endl;

        long long int currentReward = rewards[i];

        buildPaths(currentReward, i);
    }

    cout << maxReward << endl;

    return 0;
}
/*
 *
 * We want to check the next two projects starting from now and then we want to check the next two projects after that etc.
 *
 *
 * 1 6 = 5
 * 1 2 = 3
 * 3 4 = 8
 * 1 2, 3 4 = 15
 *
 * Map:
 * Key -> Value
 * 3 -> 1 2
 * 5 -> 1 6
 * 8 -> 3 4
 * 15 -> 1 2, 3 4
 *
 * We sort by start time in a struct that has start time end time and value
 * We scan the struct to go through various paths and store the result in a map where the key is the money and the value is the path
 *
 * int currentPStart = 0; //Start of current event
        currentPStart = startTimes[i];

        int currentPEnd = endTimes[i]; //End of current event

        int currentPStartEnd = currentPStart;
        currentPStartEnd *= 10;
        currentPStartEnd += currentPEnd; //Joining the start and end of current event

        int currentPath = currentPStartEnd;

 *
 */
