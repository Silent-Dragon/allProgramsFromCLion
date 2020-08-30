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

long long int n = 0; //applicants
long long int m = 0; //apartments
long long int k = 0; //maximum allowed difference
long long int cnt = 0; //counter of matched apartments
//multiset <int> desiredSize;
multiset <int> actualSize;
multiset <int>::iterator bestApartment;

int main() {
  //  freopen("in.txt", "r", stdin);

    cin >> n >> m >> k;

    long long int desiredSize[n];
    //long long int actualSize[m];
    //long long int visited[m];
    //memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        cin >> desiredSize[i];
    }
    sort(desiredSize, desiredSize + n);

    for (int i = 0; i < m; i++) {
        int inputForActualSize = 0;
        cin >> inputForActualSize;

        actualSize.insert(inputForActualSize);
    }

    //long long int N = sizeof(desiredSize) / sizeof(desiredSize[0]);
    //long long int M = sizeof(actualSize) / sizeof(actualSize[0]);
    //sort(desiredSize, desiredSize + N);
    //sort(actualSize, actualSize + M);


    for (int i = 0; i < n; i++) {
        bestApartment = actualSize.lower_bound(desiredSize[i] - k);

        if (bestApartment != actualSize.end() && *bestApartment <= desiredSize[i] + k) {
            cnt++;
            actualSize.erase(bestApartment);
        }
    }

    cout << cnt << endl;

    return 0;
}
