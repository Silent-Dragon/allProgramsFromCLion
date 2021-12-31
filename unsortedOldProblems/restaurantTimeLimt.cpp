#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0; //number of customers
vector <pair <int, int> > timesOfCustomers;
int minStart = 0;
int maxEnd = 0;
int startTime = 0;
int endTime = 0;
int cnt = 0;
int maxCnt = 0;

int main() {
    //  freopen("in.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int startTime = 0;
        int endTime = 0;
        cin >> startTime >> endTime;
        timesOfCustomers.push_back({startTime, endTime});

        if (startTime < minStart) {
            minStart = startTime;
        }

        if (endTime > maxEnd) {
            maxEnd = endTime;
        }
    }

    for (int i = minStart; i < maxEnd; i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if (timesOfCustomers[j].first <= i && timesOfCustomers[j].second >= i) {
                cnt++;
            }
        }
        if (cnt > maxCnt) {
            maxCnt = cnt;
        }
    }

    cout << maxCnt << endl;

    return 0;
}
