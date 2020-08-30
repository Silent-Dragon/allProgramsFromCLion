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
long long int currentStart = 0;
long long int currentDistance = 0;
long long int maxLength = 0;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> n;

    int positionOfTrafficLights[x + 1];
    memset(positionOfTrafficLights, 0, sizeof(positionOfTrafficLights));

    positionOfTrafficLights[0] = 1;
    positionOfTrafficLights[x] = 1;

    for (int i = 0; i < n; i++) {
        int m = 0;
        cin >> m;
        positionOfTrafficLights[m] = 1;

        currentStart = 0;
        for (int j = 1; j <= x; j++) {
            if (positionOfTrafficLights[j] == 1) {
                currentDistance = j - currentStart;
                if (currentDistance > maxLength) {
                    maxLength = currentDistance;
                }
                currentDistance = 0;
                currentStart = j;
            }
        }
        cout << maxLength << " ";

        currentStart = 0;
        maxLength = 0;
    }
    return 0;
}
