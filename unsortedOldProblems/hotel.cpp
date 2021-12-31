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

long long int n = 0; //number of people
multiset <pair <int, int>> startAndEndTimesRooms;
pair <int, int> startAndEndTimesPeople;
long long int rooms = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> startAndEndTimesPeople[i].first;
        cin >> startAndEndTimesPeople[i].second;
    }
    sort(startAndEndTimesPeople.begin(), startAndEndTimesPeople.end());

    for (int i = 0; i < n; i++) {


    }


    cout << rooms << endl;

    return 0;
}