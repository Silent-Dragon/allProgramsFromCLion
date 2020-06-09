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
    map <pair <int, int>, int> myMap;

    ///insertion
    myMap[{2,0}] = 63;
    myMap[{2, 1}] = 79;
    myMap[{5,2}] = 25;
    myMap[{1,6}] = 1;
    myMap[{0, 2}] = 84;

    for (auto iterator = myMap.begin(); iterator != myMap.end(); ++iterator) {
        //do action here including printing item in map:
        cout << iterator->first.first; //this prints the key
        cout << iterator->first.second; //this prints the key
        cout << iterator->second; //this prints the value
    }

    ///start-min, end-max
    cout << myMap.begin()->second << " " << myMap.rbegin()->second << endl;

    ///find by key
    pair <int, int> wantedKey = {2, 0};
    cout << myMap.find(wantedKey)->second;

    ///upper-lower bound
    int wantedValue = 25;
    cout << myMap.upper_bound(wantedKey)->second << " " << myMap.lower_bound(wantedKey)->second << endl;

    ///deletion
    myMap.erase(wantedKey);
    ///deleting first and last
    myMap.erase(myMap.begin());
    myMap.erase(--myMap.end());

    ///clear
    myMap.clear();

    return 0;
}
