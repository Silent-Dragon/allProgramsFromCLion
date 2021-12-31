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
    map <pair <int, int>, pair <int, int>> myMap;

    ///insertion
    myMap[{2,0}] = {63, 3};
    myMap[{2, 1}] = {92, 5};
    myMap[{5,2}] = {6, 101};
    myMap[{1,6}] = {9876, 4};
    myMap[{0, 2}] = {81, 9};

    for (auto iterator = myMap.begin(); iterator != myMap.end(); ++iterator) {
        //do action here including printing item in map:
        cout << iterator->first.first << " "; //this prints the key
        cout << iterator->first.second << " ,"; //this prints the key
        cout << iterator->second.first << " "; //this prints the value
        cout << iterator->second.second << "  "; //this prints the value
    }

    ///start-min, end-max
    cout << myMap.begin()->second.first << " " << myMap.rbegin()->second.first << endl;

    ///find by key
    pair <int, int> wantedKey = {0, 2};
    cout << myMap.find(wantedKey)->second.second;

    ///upper-lower bound
    pair <int, int> wantedValue = {22, 7};
    cout << myMap.upper_bound(wantedKey)->second.first << " " << myMap.lower_bound(wantedKey)->second.first << endl;

    ///deletion
    myMap.erase(wantedKey);
    ///deleting first and last
    myMap.erase(myMap.begin());
    myMap.erase(--myMap.end());

    ///clear
    myMap.clear();

    return 0;
}
