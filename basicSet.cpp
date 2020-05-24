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
    int wantedValue = 5;
    mySet.erase(5);

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