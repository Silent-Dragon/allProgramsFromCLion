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
    vector <pair <int, pair <int, int>>> myVector[n][n];

    ///adding values
    myVector[0][0].push_back({126, {41, 75}});
    myVector[0][1].push_back({2, {4, 5}});
    myVector[2][1].push_back({99, {9, 7512}});
    myVector[0][1].push_back({54, {48, 7}});
    myVector[1][2].push_back({63, {24, 751}});

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto itr : myVector[i][j]) {
                cout << itr.first << " ";
                cout << itr.second.first << " ";
                cout << itr.second.second << " ";
            }
        }
    }
    cout << endl;

    ///start and end
    cout << myVector[0][0].begin()->first << " " << myVector[2][1].end()->second.first << endl;

    ///sort
    sort(myVector[1][0].begin(), myVector[1][0].end());

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto itr : myVector[i][j]) {
                cout << itr.first << " ";
                cout << itr.second.first << " ";
                cout << itr.second.second << " ";
            }
        }
    }
    cout << endl;

    ///min and max elements
    cout << (*min_element(myVector[0][0].begin(), myVector[0][0].end())).first << " " << max_element(myVector[2][1].begin(), myVector[2][1].end())->second.first << endl;

    ///find by index and value
    int wantedIndex = 0;
    int wantedIndex2 = 1;
    pair <int, pair <int, int>> wantedValue = {126, {41, 75}};
    cout << (*find(myVector[0][0].begin(), myVector[0][0].end(), wantedValue)).second.first << endl;
    //myVector[wantedIndex][wantedIndex2].first

    ///upper and lower bound - KEEP IN MIND THAT VECTOR HAS BEEN SORTED
    cout << (*upper_bound(myVector[0][0].begin(), myVector[0][0].end(), wantedValue)).second.second << " ";
    cout << lower_bound(myVector[0][0].begin(), myVector[0][0].end(), wantedValue)->first << endl;

    ///fin
    return 0;
}
