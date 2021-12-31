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

int n = 0; //size of our sequence
vector <int> cand;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int a[n + 1];
    int minNumber[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        while (cand.size() > 0 && a[cand.back()] >= a[i]) {
            cand.pop_back();
        }

        if (cand.size()) {
            cout << cand.back() + 1 << " ";
        } else {
            cout << 0 << " ";
        }

        cand.push_back(i);
    }

    cout << endl;

    return 0;
}
