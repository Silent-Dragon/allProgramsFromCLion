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

long long int n = 0; //number of movies
long long int k = 0; //number of people
multiset <int> currentTimes;
long long int movies = 0; //movies watched

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    pair <int, int> startAndEndTimes[n];
    for (int i = 0; i < n; i++) {
        cin >> startAndEndTimes[i].second >> startAndEndTimes[i].first;
    }
    sort(startAndEndTimes, startAndEndTimes + n);

    for (int i = 0; i < k; i++) {
        currentTimes.insert(0);
    }


    for (int i = 0; i < n; i++) {
        multiset<int>::iterator upperBoundResult;
        upperBoundResult = currentTimes.upper_bound(startAndEndTimes[i].second);

        if (upperBoundResult != currentTimes.begin()) {
            upperBoundResult--;
            movies++;
            currentTimes.erase(upperBoundResult);
            currentTimes.insert(startAndEndTimes[i].first);

        }


    }


    cout << movies << endl;

    return 0;
}
