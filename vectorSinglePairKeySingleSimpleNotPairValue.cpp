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

///file for all columns for vector
int main() {
    ///init
    vector <int> myVector;

    ///adding values
    myVector[0] = 5;
    myVector[1] = 9999;
    myVector[2] = 1;
    myVector.push_back(60);
    myVector.push_back(919);

    ///iterating and printing
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << " ";
    }
    cout << endl;

    ///start and end
    cout << *myVector.begin() << " " << *myVector.end() << endl;

    ///sort
    sort(myVector.begin(), myVector.end());

    ///iterating and printing
    for (auto itr = 0; itr != myVector.size(); itr++) {
        ///value
        cout << itr << " ";
    }
    cout << endl;

    ///min and max elements
    cout << *min_element(myVector.begin(), myVector.end()) << " " << *max_element(myVector.begin(), myVector.end()) << endl;

    ///find by index and value
    int wantedIndex = 4;
    int wantedValue = 60;
    cout << myVector[4] << " " << *find(myVector.begin(), myVector.end(), wantedValue) << endl;

    ///upper and lower bound - KEEP IN MIND THAT VECTOR HAS BEEN SORTED
    cout << *upper_bound(myVector.begin(), myVector.end(), wantedValue) << " ";
    cout << *lower_bound(myVector.begin(), myVector.end(), wantedValue) << endl;

    ///fin
    return 0;
}
