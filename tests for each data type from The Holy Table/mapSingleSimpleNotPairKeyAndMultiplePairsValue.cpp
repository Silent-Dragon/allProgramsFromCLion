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
    map <int, pair <pair <int, int>, pair <int, int>>> myMap;

    ///insertion
    myMap[54] = {{63, 9731}, {2, 74}};
    myMap[82] = {{16, 31}, {84, 90}};
    myMap[872] = {{12, 973}, {53, 1}};
    myMap[8] = {{894, 731}, {1, 14}};
    myMap[202] = {{7434, 24}, {942, 7}};

    for (auto iterator = myMap.begin(); iterator != myMap.end(); ++iterator) {
        //do action here including printing item in map:
        cout << iterator->first << " "; //this prints the key
        cout << iterator->second.first.first << " "; //this prints the value
        cout << iterator->second.first.second << " "; //this prints the value
        cout << iterator->second.second.first << " "; //this prints the value
        cout << iterator->second.second.second << ", "; //this prints the value
    }
    cout << endl;

    ///start-min, end-max
    cout << myMap.begin()->second.first.first << " " << myMap.rbegin()->second.first.second << endl;

    ///find by key
    int wantedKey = 202;
    cout << myMap.find(wantedKey)->second.first.first;

    ///upper-lower bound
    pair <pair <int, int>, pair <int, int>> wantedValue = {{63, 9731}, {2, 74}};
    cout << myMap.upper_bound(wantedKey)->second.first.first << " " << myMap.lower_bound(wantedKey)->second.first.first << endl;

    ///deletion
    myMap.erase(wantedKey);
    ///deleting first and last
    myMap.erase(myMap.begin());
    myMap.erase(--myMap.end());

    ///clear
    myMap.clear();

    return 0;
}
