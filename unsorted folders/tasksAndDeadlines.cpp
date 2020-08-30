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

long long int n = 0; //number of tasks
long long int duration = 0;
long long int deadline = 0;
multiset < pair <int, int> >durationsAndDeadlines;
bool canContinue = true;
long long int currentTime = 0;
long long int points = 0;//points we have

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        duration = 0;
        deadline = 0;
        cin >> duration >> deadline;

        durationsAndDeadlines.insert(make_pair(duration, deadline));
    }


    for (auto i = durationsAndDeadlines.begin(); i != durationsAndDeadlines.end(); i++) {
        currentTime += i->first;

        canContinue = true;

        points += i->second - currentTime;
        // cout << "Points are " << points << endl;
    }


    cout << points << endl;

    return 0;
}
