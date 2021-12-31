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
    pair<int, int> myArray[n];

    ///adding values
    myArray[0] = {5, 6};
    myArray[1] = {321, 1};
    myArray[2] = {999, 4};
    myArray[3] = {77, 2};
    myArray[4] = {86, 61};

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        ///index and value
        cout << i << " ";
        cout << myArray[i].first << " ";
        cout << myArray[i].second << "  ";
    }
    cout << endl;

    ///sort
    sort(myArray, myArray + n);

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        ///value
        cout << myArray[i].first << " ";
        cout << myArray[i].second << "  ";
    }
    cout << endl;

    ///start and end
    cout << myArray[0].first << " " << myArray[n - 1].first << endl;

    ///min and max elements
  //  cout << *min_element(myArray, myArray + n) << " " << *max_element(myArray, myArray + n) << endl;

    ///find by index
    int wantedIndex = 4;
    cout << myArray[4].first << endl;

    ///upper and lower bound - KEEP IN MIND THAT ARRAY HAS BEEN SORTED
 //   cout << upper_bound(myArray, myArray + n, wantedValue) << " ";
  //  cout << lower_bound(myArray, myArray + n, wantedValue) << endl;

    ///fin

    return 0;
}
