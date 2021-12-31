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

long long int n = 0; //size of our sequence
long long int desiredSum = 0;
long long int delta = 0;
bool foundAnswer;
map <int, int> appForEachNumber;

int main() {
    cin >> n >> desiredSum;

    long long int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        appForEachNumber[a[i]] = i + 1;
        //9 -> 1, 6
        //2 -> 2, 4
        //4 -> 3, 5
    }

    for (int i = 0; i < n; i++) {
        delta = desiredSum - a[i];
        if (appForEachNumber[delta] > 0 && appForEachNumber[delta] != i + 1) {
            cout << i + 1 << " " << appForEachNumber[delta];
            exit(0);
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
