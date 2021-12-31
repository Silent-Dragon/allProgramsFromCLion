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
    vector <int> myArray[n];

    ///adding values
    myArray[0].push_back(3);
    myArray[0].push_back(999);
    myArray[0].push_back(87);
    myArray[1].push_back(66);
    myArray[2].push_back(234);
    myArray[2].push_back(98);
    myArray[3].push_back(12);
    myArray[3].push_back(5);
    myArray[4].push_back(80);

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (auto itr = myArray[i].begin(); itr != myArray[i].end(); itr++) {
            ///index and value
            cout << *itr << "  ";
        }
    }
    cout << endl;

    ///sort
    sort(myArray, myArray + n);

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (auto itr = myArray[i].begin(); itr != myArray[i].end(); itr++) {
            ///index and value
            cout << *itr << "  ";
        }
    }
    cout << endl;

    ///start and end
   // cout << myArray[0] << " " << myArray[n - 1] << endl;

    ///min and max elements
  //  cout << *min_element(myArray, myArray + n) << " " << *max_element(myArray, myArray + n) << endl;

    ///find by index and value
    int wantedIndex = 4;
    int wantedValue = 66;
   // cout << myArray[4] << " " << find(myArray, myArray + n, wantedValue) << endl;

    ///upper and lower bound - KEEP IN MIND THAT ARRAY HAS BEEN SORTED
   // cout << upper_bound(myArray, myArray + n, wantedValue) << " ";
  //  cout << lower_bound(myArray, myArray + n, wantedValue) << endl;

    ///fin

    return 0;
}
