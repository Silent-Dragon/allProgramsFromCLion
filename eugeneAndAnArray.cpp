/* Constructive Algorithms Template
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 1e7; //max n we can have
long long int n, noForAns, isThereDuplicate, lastPosOfRecentDupl;
map <long long int, long long int> cnt;

void solve() {
    cin >> n;

    long long int a[n];
    long long int prefixSumsFromStart[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (i != 0) {
            prefixSumsFromStart[i] = prefixSumsFromStart[i - 1] + a[i];
        } else {
            prefixSumsFromStart[i] = a[i];
        }
    }


    cnt[0] = -1;
    for (int i = 0; i < n; i++) {
        if (cnt.count(prefixSumsFromStart[i])) { //duplicate
            if (cnt[prefixSumsFromStart[i]] + 2 < lastPosOfRecentDupl) { //use lastposofrecentdupl
                noForAns += (i + 1) - (lastPosOfRecentDupl);
            } else { //use normal place
                noForAns += (i + 1) - (cnt[prefixSumsFromStart[i]] + 2);
                lastPosOfRecentDupl = cnt[prefixSumsFromStart[i]] + 2;
            }

            isThereDuplicate = 1;
        } else if (isThereDuplicate) { //no current duplicate, but previous one
            noForAns += i - lastPosOfRecentDupl + 1;
        } else { //no duplicate
            noForAns += i + 1;
        }

        cnt[prefixSumsFromStart[i]] = i;
    }

    cout << noForAns << endl;

}

int main() {

    solve();
    return 0;
}