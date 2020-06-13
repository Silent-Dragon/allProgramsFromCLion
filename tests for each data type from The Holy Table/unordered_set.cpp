#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <iterator>

using namespace std;

int main() {

    ///init
    unordered_set <int> mySet;

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

    ///erase value and start
    int wantedValue = 5;
    mySet.erase(5);

    mySet.erase(mySet.begin());

    ///iterating and printing value
    for (auto iterator = mySet.begin(); iterator != mySet.end(); ++iterator) {
        cout << *iterator << " "; //this prints the item of the set in the current place
    }
    cout << endl;

    ///start and end (not working)
    cout << *mySet.begin() << " ";

    ///min and max
    cout << *min_element(mySet.begin(), mySet.end()) << *max_element(mySet.begin(), mySet.end()) << endl;

    ///find
    int wantedValue2 = 30;
    cout << *mySet.find(wantedValue2) << endl;

    ///upper/lower bound cannot be done since it cannot be sorted

    ///clear
    mySet.clear();

    return 0;
}