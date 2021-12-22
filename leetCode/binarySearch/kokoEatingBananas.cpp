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

int n = 0;
int h = 0;
int maxK = -1;

int hoursNeededToFinishPilesWithCurrentEatingSpeed(int eatingSpeed, vector <int> piles) {
    int cntForHours = 0;

    //Here you can either do a specific function or leave this blank if you are doing a simple search
    for (int i = 0; i < piles.size(); i++) {
        if (piles[i] % eatingSpeed == 0) {
            cntForHours += piles[i] / eatingSpeed;
        } else {
            cntForHours += (piles[i] / eatingSpeed) + 1;
        }
    }

    //computations
    return cntForHours;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h;

    vector <int> piles;
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
        if (piles[i] > maxK) {
            maxK = piles[i];
        }
    }

    int l = 1;
    int r = maxK;
    int k, ans;
    int minHours = 1e9;

    while (l <= r) {
        k = l + (r - l) / 2;

        if (minHours >= hoursNeededToFinishPilesWithCurrentEatingSpeed(k, piles)) {
            ans = k;
            r = k - 1;
        } else {
            l = k + 1;
        }
    }

    cout << ans;

    return 0;
}