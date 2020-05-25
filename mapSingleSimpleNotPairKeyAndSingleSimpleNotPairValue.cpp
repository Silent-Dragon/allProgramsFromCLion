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

int main() {
    ///init
    map <int, int> myMap;

    ///insertion
    myMap[0] = 63;
    myMap[1] = 5;
    myMap[2] = 97;
    myMap[3] = 22;
    myMap[4] = 1;

    ///iterating and printing
    for (auto itr = myMap.begin(); itr != myMap.end(); itr++) {
        cout << itr-> first << " " << itr->second << endl;
    }

    ///start-min, end-max
    cout << *myMap.begin() << " " << *myMap.rbegin() << endl;

    ///find by key
    int wantedKey = 3;
    cout << *myMap.find(3);

    ///upper-lower bound
    int wantedValue = 40;
    cout << *myMap.upper_bound(wantedValue) << " " << *myMap.lower_bound(wantedValue) << endl;

    ///deletion
    myMap.erase(wantedValue);

    ///clear
    myMap.clear();

    return 0;
}
