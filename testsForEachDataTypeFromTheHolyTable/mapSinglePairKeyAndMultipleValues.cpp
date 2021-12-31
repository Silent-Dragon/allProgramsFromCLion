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
    map <pair <int, int>, vector <int>> myMap;

    ///insertion
    myMap[{54, 98}] = {63, 2, 74};
    myMap[{82, 6}] = {16, 84};
    myMap[{872, 92}] = {12, 53, 1, 472};
    myMap[{822446, 7}] = {894, 1, 14, 66, 24};
    myMap[{202, 974}] = {7434};

    for (auto iterator = myMap.begin(); iterator != myMap.end(); ++iterator) {
        //do action here including printing item in map:
        cout << "Key: ";
        cout << iterator->first.first << " "; //this prints the key
        cout << iterator->first.second << " "; //this prints the key
        for (auto iterator2 = iterator->second.begin(); iterator2 != iterator->second.end(); iterator2++) {
            cout << " Value: ";
            cout << *iterator2 << " "; //this prints the value
        }
        cout << endl;
    }
    cout << endl;

    ///start-min, end-max
    cout << myMap.begin()->second[2] << " " << myMap.rbegin()->second[0] << endl;

    ///find by key
    pair <int, int> wantedKey = {202, 974};
    cout << *myMap.find(wantedKey)->second.begin();

    ///upper-lower bound
    cout << myMap.upper_bound(wantedKey)->second[1] << " " << *myMap.lower_bound(wantedKey)->second.rbegin() << endl;

    ///deletion
    myMap.erase(wantedKey);
    ///deleting first and last
    myMap.erase(myMap.begin());
    myMap.erase(--myMap.end());

    ///clear
    myMap.clear();

    return 0;
}
