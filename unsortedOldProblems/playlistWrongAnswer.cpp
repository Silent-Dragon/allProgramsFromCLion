#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0; //number of songs
map <int, int> usedSongs;//used songs map
int currentCnt = 0;
int maxCnt = 0;

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n;

    int songCodes[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> songCodes[i];
    }

    for (int i = 0; i < n; i++) {
        currentCnt++;
        if (usedSongs.count(songCodes[i])) {
            //used
            if (currentCnt > maxCnt) {
                maxCnt = currentCnt;
            }
            usedSongs.clear();
            currentCnt = 0;
        } else {
            //not used
            usedSongs[songCodes[i]] = 1;
        }
    }

    if (maxCnt <= 0) {
        if (currentCnt != 0) {
            cout << currentCnt << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        cout << maxCnt << endl;
    }

    return 0;
}
