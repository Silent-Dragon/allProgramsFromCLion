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
    vector <int> myVector[n][n];

    ///adding values
    myVector[0][0].push_back(9);
    myVector[0][1].push_back(37);
    myVector[1][2].push_back(125);
    myVector[0][2].push_back(53);
    myVector[2][0].push_back(345);

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto itr : myVector[i][j]) {
                cout << itr << " ";
            }
        }
    }
    cout << endl;


    ///start and end
    cout << *myVector[0][0].begin() << " " << *myVector[1][2].rbegin() << endl;

    ///sort
    sort(myVector[0][0].begin(), myVector[0][0].end());

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto itr : myVector[i][j]) {
                cout << itr << " ";
            }
        }
    }
    cout << endl;

    ///min and max elements
    cout << *min_element(myVector[1][2].begin(), myVector[1][2].end()) << " " << *max_element(myVector[0][1].begin(), myVector[0][1].end()) << endl;

    ///find by index and value
    int wantedIndex = 1;
    int wantedIndex2 = 2;
    int wantedValue = 53;
    cout << *myVector[wantedIndex][wantedIndex2].begin() << " " << *find(myVector[1][2].begin(), myVector[1][2].end(), wantedValue) << endl;

    ///upper and lower bound - KEEP IN MIND THAT VECTOR HAS BEEN SORTED
    cout << *upper_bound(myVector[wantedIndex][wantedIndex2].begin(), myVector[wantedIndex][wantedIndex2].end(), wantedValue) << " ";
    cout << *lower_bound(myVector[wantedIndex][wantedIndex2].begin(), myVector[wantedIndex][wantedIndex2].end(), wantedValue) << endl;

    ///fin
    return 0;
}
