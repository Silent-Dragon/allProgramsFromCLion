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
    vector <pair <pair <int, int>, pair <int, int>>> myVector;

    ///adding values
    myVector.push_back({{9, 126}, {41, 75}});
    myVector.push_back({{219, 2}, {4, 5}});
    myVector.push_back({{99, 1}, {9, 7512}});
    myVector.push_back({{54, 26}, {48, 7}});
    myVector.push_back({{23, 63}, {24, 751}});

    ///iterating and printing
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i].first.first << " ";
        cout << myVector[i].first.second << " ";
        cout << myVector[i].second.first << " ";
        cout << myVector[i].second.second << " ";
    }
    cout << endl;

    ///start and end
    cout << myVector.begin()->first.first << " " << myVector.end()->second.first << endl;

    ///sort
    sort(myVector.begin(), myVector.end());

    ///iterating and printing
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i].first.first << " ";
        cout << myVector[i].first.second << " ";
        cout << myVector[i].second.first << " ";
        cout << myVector[i].second.second << " ";
    }
    cout << endl;

    ///min and max elements
    cout << (*min_element(myVector.begin(), myVector.end())).first.first << " " << max_element(myVector.begin(), myVector.end())->second.first << endl;

    ///find by index and value
    int wantedIndex = 2;
    pair <pair <int, int>, pair <int, int>> wantedValue = {{9, 126}, {41, 75}};
    cout << myVector[wantedIndex].first.second << " " << (*find(myVector.begin(), myVector.end(), wantedValue)).first.first << endl;

    ///upper and lower bound - KEEP IN MIND THAT VECTOR HAS BEEN SORTED
    cout << (*upper_bound(myVector.begin(), myVector.end(), wantedValue)).second.second << " ";
    cout << lower_bound(myVector.begin(), myVector.end(), wantedValue)->first.second << endl;

    ///fin
    return 0;
}
