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

///file for all columns for string
int main() {
    ///init
    string myString;

    ///adding values
    myString = "Heelo";
    myString[2] = 'l';

    ///iterating and printing
    for (int i = 0; i < myString.size(); i++) {
        ///index and value
        cout << i << " ";
        cout << myString[i] << " ";
    }
    cout << endl;

    cout << myString << endl;

    ///start and end
    cout << *myString.begin() << " " << *myString.rbegin() << endl;

    ///find by index
    int wantedIndex = 4;
    cout << myString[3] << endl;

    ///fin

    return 0;
}
