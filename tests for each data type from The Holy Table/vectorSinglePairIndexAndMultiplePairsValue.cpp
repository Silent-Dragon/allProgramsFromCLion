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
    int n = 3;

    ///init
    vector <pair <pair <int, int>, pair <int, int>>> myVector[n][n];

    ///adding values
    myVector[0][0].push_back({{9, 126}, {41, 75}});
    myVector[1][0].push_back({{219, 2}, {4, 5}});
    myVector[0][0].push_back({{99, 1}, {9, 7512}});
    myVector[2][1].push_back({{54, 26}, {48, 7}});
    myVector[1][2].push_back({{23, 63}, {24, 751}});

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto itr : myVector[i][j]) {
                cout << itr.first.first << " ";
                cout << itr.first.second << " ";
                cout << itr.second.first << " ";
                cout << itr.second.second << " ";
            }
        }
    }
    cout << endl;

    ///start and end
    cout << myVector[0][0].begin()->first.first << " " << myVector[2][1].end()->second.first << endl;

    ///sort
    sort(myVector[0][0].begin(), myVector[0][0].end());

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto itr : myVector[i][j]) {
                cout << itr.first.first << " ";
                cout << itr.first.second << " ";
                cout << itr.second.first << " ";
                cout << itr.second.second << " ";
            }
        }
    }
    cout << endl;

    ///min and max elements
    cout << (*min_element(myVector[1][2].begin(), myVector[1][2].end())).first.first << " " << max_element(myVector[2][1].begin(), myVector[2][1].end())->second.first << endl;

    ///find by index and value
    int wantedIndex = 0;
    int wantedIndex2 = 0;
    pair <pair <int, int>, pair <int, int>> wantedValue = {{9, 126}, {41, 75}};
    cout << (*find(myVector[0][0].begin(), myVector[0][0].end(), wantedValue)).first.first << endl;
    //myVector[wantedIndex][wantedIndex2].first.second

    ///upper and lower bound - KEEP IN MIND THAT VECTOR HAS BEEN SORTED
    cout << (*upper_bound(myVector[2][1].begin(), myVector[2][1].end(), wantedValue)).second.second << " ";
    cout << lower_bound(myVector[1][2].begin(), myVector[1][2].end(), wantedValue)->first.second << endl;

    ///fin
    return 0;
}
