#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

long long int n = 0;

map <int, int> visitedNumbers;

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;


    for (int i = 0; i < n; i++) {
        long long int x = 0;
        cin >> x;
        visitedNumbers[x] = 1;
    }

    cout << visitedNumbers.size() << endl;
    return 0;
}
