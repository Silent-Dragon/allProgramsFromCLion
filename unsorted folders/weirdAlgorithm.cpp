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
long long int x = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    x = n;
    while (x != 1) {
        cout << x << " ";

        if (x % 2 == 0) {
            x /= 2;
        } else {
            x = x * 3 + 1;
        }
    }

    cout << 1;


    return 0;
}
