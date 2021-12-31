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
    map <int, pair <int, int>> myMap;

    ///insertion
    myMap[0] = {63, 3};
    myMap[1] = {92, 5};
    myMap[2] = {6, 101};
    myMap[3] = {9876, 4};
    myMap[4] = {81, 9};

    cout << "Hi" << endl;
    for (auto iterator = myMap.begin(); iterator != myMap.end(); ++iterator) {
        //do action here including printing item in map:
        cout << iterator->first << ", "; //this prints the key
        cout << iterator->second.first << " "; //this prints the value
        cout << iterator->second.second << "  "; //this prints the value
    }

    ///start-min, end-max
    cout << myMap.begin()->second.first << " " << myMap.rbegin()->second.first << endl;

    ///find by key
    int wantedKey = 2;
    cout << myMap.find(wantedKey)->second.second;

    ///upper-lower bound
    pair <int, int> wantedValue = {81, 9};
    cout << myMap.upper_bound(wantedKey)->second.first << " " << myMap.lower_bound(wantedKey)->second.first << endl;

    ///deletion
    myMap.erase(wantedKey);
    ///deleting first and last
    myMap.erase(myMap.begin());
    myMap.erase(--myMap.end());

    ///clear
    myMap.clear();

    ///init
    set<int> mySet;

    ///insert
    mySet.insert(5);
    mySet.insert(877);
    mySet.insert(2);
    mySet.insert(30);
    mySet.insert(94);

    ///iterating and printing value
    for (auto iterator = mySet.begin(); iterator != mySet.end(); ++iterator) {
        cout << *iterator << " "; //this prints the item of the set in the current place
    }
    cout << endl;

    ///erase
    int myWantedValue = 5;
    mySet.erase(myWantedValue);

    mySet.erase(mySet.begin());
    mySet.erase(--mySet.end());

    ///iterating and printing value
    for (auto iterator = mySet.begin(); iterator != mySet.end(); ++iterator) {
        cout << *iterator << " "; //this prints the item of the set in the current place
    }
    cout << endl;

    ///start (min) and end (max)
    cout << *mySet.begin() << " " << *mySet.rbegin() << endl;

    ///find
    int wantedValue2 = 30;
    cout << *mySet.find(wantedValue2) << endl;

    ///upper/lower bound
    cout << *mySet.upper_bound(wantedValue2) << " " << *mySet.lower_bound(wantedValue2) << endl;

    ///clear
    mySet.clear();

    return 0;
}
