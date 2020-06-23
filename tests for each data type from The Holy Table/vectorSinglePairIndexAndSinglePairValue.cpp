#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

///file for all columns for vector
int main() {
    int n = 5;

    ///init
    vector <pair <int, int>> myVector[n][n];

    ///adding values
    myVector[0][0].push_back({5, 84});
    myVector[0][1].push_back({9999, 49});
    myVector[1][2].push_back({1, 72});
    myVector[0][2].push_back({112, 60});
    myVector[2][0].push_back({48, 919});

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto itr : myVector[i][j]) {
                cout << itr.first << " ";
                cout << itr.second << " ";
            }
        }
    }
    cout << endl;


    ///start and end
    cout << (*myVector[0][0].begin()).first << " " << myVector[1][2].rbegin()->second << endl;

    ///sort
    sort(myVector[0][0].begin(), myVector[0][0].end());

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto itr : myVector[i][j]) {
                cout << itr.first << " ";
                cout << itr.second << " ";
            }
        }
    }
    cout << endl;

    ///min and max elements
    cout << (*min_element(myVector[1][2].begin(), myVector[1][2].end())).second << " " << max_element(myVector[0][1].begin(), myVector[0][1].end())->first << endl;

    ///find by index and value
    int wantedIndex = 0;
    int wantedIndex2 = 2;
    pair <int, int> wantedValue = {112, 60};
    cout << myVector[wantedIndex][wantedIndex2].begin()->second << " " << (*find(myVector[1][2].begin(), myVector[1][2].end(), wantedValue)).second << endl;

    ///upper and lower bound - KEEP IN MIND THAT VECTOR HAS BEEN SORTED
    cout << upper_bound(myVector[wantedIndex][wantedIndex2].begin(), myVector[wantedIndex][wantedIndex2].end(), wantedValue)->first << " ";
    cout << (*lower_bound(myVector[wantedIndex][wantedIndex2].begin(), myVector[wantedIndex][wantedIndex2].end(), wantedValue)).first << endl;

    ///fin
    return 0;
}
