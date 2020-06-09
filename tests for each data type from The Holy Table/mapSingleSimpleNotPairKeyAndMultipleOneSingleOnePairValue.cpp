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
    map <int, pair <int, pair <int, int>>> myMap;

    ///insertion
    myMap[54] = {63, {2, 74}};
    myMap[1] = {89, {64, 7}};
    myMap[72] = {32, {91, 8}};
    myMap[91] = {9, {3, 1}};
    myMap[89] = {2, {936, 435}};

    for (auto iterator = myMap.begin(); iterator != myMap.end(); ++iterator) {
        //do action here including printing item in map:
        cout << iterator->first << " "; //this prints the key
        cout << iterator->second.first << " "; //this prints the value
        cout << iterator->second.second.first << " "; //this prints the value
        cout << iterator->second.second.second << "  "; //this prints the value
    }
    cout << endl;

    ///start-min, end-max
    cout << myMap.begin()->second.first << " " << myMap.rbegin()->second.first << endl;

    ///find by key
    int wantedKey = 54;
   // cout << myMap.find(wantedKey)->first;

    ///upper-lower bound
    pair <int, pair <int, int>> wantedValue = {63, {2, 74}};;
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
