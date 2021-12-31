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

long long int x = 0; //length of street
long long int n = 0; //number of traffic light additions
multiset <int> distances; //distances between traffic lights
multiset <int> positionsOfTrafficLights; //positions of traffic lights
int rightPosition;
int leftPosition;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> n;

    positionsOfTrafficLights.insert(0);
    positionsOfTrafficLights.insert(x);
    distances.insert(x);
    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;
        positionsOfTrafficLights.insert(a);
        rightPosition = *positionsOfTrafficLights.upper_bound(a);
        leftPosition = *prev(positionsOfTrafficLights.lower_bound(a));

        distances.erase(distances.find(rightPosition - leftPosition));

        distances.insert(rightPosition - a);
        distances.insert(a - leftPosition);

        cout << *distances.rbegin() << " ";
    }
    cout << endl;



    return 0;
}