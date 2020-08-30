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

int n = 0; //number of movies
multiset < pair <int, int> >startAndEndTimes;
bool canContinue = true;
int currentTime = 0;
int movies = 0;//movies we watched

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


    for (auto i = startAndEndTimes.begin(); i != startAndEndTimes.end(); i++) {
        if (i->second >= currentTime) {
            currentTime = i->first;
            //startAndEndTimes.erase(i);
            //will not effect since we do not go backwards
            movies++;
        }

        if (startAndEndTimes.size() == 0) {
            break;
        }
    }


    cout << movies << endl;

    return 0;
}
