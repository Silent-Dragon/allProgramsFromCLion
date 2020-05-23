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

///file for all columns for array with index of type int
int main() {

    int n = 5;

    ///init
    int myArray[n];

    ///adding values
    myArray[0] = 5;
    myArray[1] = 9999;
    myArray[2] = 1;
    myArray[3] = 66;
    myArray[4] = 235;

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        ///index and value
        cout << i << " ";
        cout << myArray[i] << ", ";
    }
    cout << endl;

    ///sort
    sort(myArray, myArray + n);

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        ///value
        cout << myArray[i] << ", ";
    }
    cout << endl;

    ///start and end
    cout << myArray[0] << " " << myArray[n - 1] << endl;

    ///min and max elements
    cout << *min_element(myArray, myArray + n) << " " << *max_element(myArray, myArray + n) << endl;

    ///find by index and value
    int wantedIndex = 4;
    int wantedValue = 5;
    cout << myArray[4] << " " << find(myArray, myArray + n, wantedValue) << endl;

    ///upper and lower bound - KEEP IN MIND THAT ARRAY HAS BEEN SORTED
    cout << upper_bound(myArray, myArray + n, wantedValue) << " ";
    cout << lower_bound(myArray, myArray + n, wantedValue) << endl;

    ///fin

    return 0;
}
