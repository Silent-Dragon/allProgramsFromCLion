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

long long int n = 0; //starting number
set <int> numbers;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;

        numbers.insert(x);
    }

    int prevNumber = 0;
    for (auto i = numbers.begin(); i != numbers.end(); i++) {
        cout << *i << endl;
        if (*i != prevNumber + 1) {
            cout << *i << endl;
            break;
        } else {
            prevNumber = *i;
        }
    }

    return 0;
}
