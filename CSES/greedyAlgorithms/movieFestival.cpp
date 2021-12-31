#include <iostream>
#include <map>
#include <utility>
#include <set>

using namespace std;

int n = 0; //number of movies
int movies = 0; //movies we watched
int currentTime = 0;

multiset <pair <int, int>> startAndEndTimes;

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
            //will not affect since we do not go backwards
            movies++;
        }

        if (startAndEndTimes.empty()) {
            break;
        }
    }


    cout << movies << endl;

    return 0;
}
