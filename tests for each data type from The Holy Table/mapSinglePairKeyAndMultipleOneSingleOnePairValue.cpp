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
    map <pair <int, int>, pair <int, pair <int, int>>> myMap;

    ///insertion
    myMap[{54, 98}] = {63, {2, 74}};
    myMap[{82, 6}] = {16, {84, 90}};
    myMap[{872, 92}] = {12, {53, 1}};
    myMap[{822446, 7}] = {894, {1, 14}};
    myMap[{202, 974}] = {7434, {942, 7}};

    for (auto iterator = myMap.begin(); iterator != myMap.end(); ++iterator) {
        //do action here including printing item in map:
        cout << iterator->first.first << " "; //this prints the key
        cout << iterator->first.second << " "; //this prints the key
        cout << iterator->second.first << " "; //this prints the value
        cout << iterator->second.second.first << " "; //this prints the value
        cout << iterator->second.second.second << "  "; //this prints the value
    }
    cout << endl;

    ///start-min, end-max
    cout << myMap.begin()->second.first << " " << myMap.rbegin()->second.first << endl;

    ///find by key
    pair <int, int> wantedKey = {202, 974};
    cout << myMap.find(wantedKey)->second.first;

    ///upper-lower bound
    pair <int, pair <int, int>> wantedValue = {63, {2, 74}};;
    cout << myMap.upper_bound(wantedKey)->second.first << " " << myMap.lower_bound(wantedKey)->second.first << endl;

    ///deletion
    myMap.erase(wantedKey);
    ///deleting first and last
    myMap.erase(myMap.begin());
    //myMap.erase(myMap.rbegin());

    ///clear
    myMap.clear();

    return 0;
}
