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
    ///init
    vector <pair <int, int>> myVector;

    ///adding values
    myVector.push_back({5, 84});
    myVector.push_back({9999, 49});
    myVector.push_back({1, 72});
    myVector.push_back({112, 60});
    myVector.push_back({48, 919});

    ///iterating and printing
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i].first << " ";
        cout << myVector[i].second << " ";
    }
    cout << endl;

    ///start and end
    cout << myVector.begin()->first << " " << (*myVector.end()).second << endl;

    ///sort
    sort(myVector.begin(), myVector.end());

    ///iterating and printing
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i].first << " ";
        cout << myVector[i].second << " ";
    }
    cout << endl;

    ///min and max elements
    cout << (*min_element(myVector.begin(), myVector.end())).first << " " << max_element(myVector.begin(), myVector.end())->second << endl;

    ///find by index and value
    int wantedIndex = 4;
    pair <int, int> wantedValue = {48, 919};
    cout << myVector[wantedIndex].second << " " << find(myVector.begin(), myVector.end(), wantedValue)->first << endl;

    ///upper and lower bound - KEEP IN MIND THAT VECTOR HAS BEEN SORTED
    cout << (*upper_bound(myVector.begin(), myVector.end(), wantedValue)).first << " ";
    cout << lower_bound(myVector.begin(), myVector.end(), wantedValue)->second << endl;

    ///fin
    return 0;
}
