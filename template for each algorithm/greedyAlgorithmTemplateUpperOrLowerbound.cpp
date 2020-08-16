#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, x;
vector <int> v;
multiset <int> v2;

int pods, desired;
multiset <int>::iterator complimentingPointer;

void greedyAlgorithm() {
    sort(v.begin(), v.end());

    while (v2.size() > 0) {
        desired = x - *v2.begin();
        v2.erase(v2.begin());

        complimentingPointer = v2.lower_bound(desiredWeight + 1);
        if (complimentingPointer != v2.begin()) {
            complimentingPointer--;
            v2.erase(complimentingPointer);
        }

        cnt++;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;


    for (int i = 0; i < n; i++) {
        int m = 0;
        cin >> m;
        v.push_back(m);
        v2.insert(m);
    }

    greedyAlgorithm();

    cout << cnt << endl;

    return 0;
}