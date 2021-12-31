#include <iostream>
#include <cmath>
#include <string>
#include <array>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>


using namespace std;

#define pb push_back

vector <int> v;

int main() {

    array <int, 3> myArray;

    map <pair <int, int>, array <int, 3>> myMap;

    myMap[{1, 2}] = {1, 2, 3};
    myMap[{1, 3}] = {88, 9, 7};
    myMap[{2, 3}] = {7, 5, 555};

    for (auto iterator = myMap.begin(); iterator != myMap.end(); ++iterator) {
        //do action here including printing item in map:
        cout << iterator->first.first << " "; //this prints the key
        cout << iterator->first.second << " "; //this prints the key
        cout << iterator->second[1] << " "; //this prints the value
        cout << iterator->second[0] << endl; //this prints the value
    }

    /*
    int n = 4;
    int myArray[n];

    myArray[0] = 8;
    myArray[1] = 123;
    myArray[2] = 95;
    myArray[3] = 4;


    for (int i = 0; i < n; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    pair <int, int> myArrayOfPairs[n];

    myArrayOfPairs[0] = {6, 5};
    myArrayOfPairs[1] = {192, 44};
    myArrayOfPairs[2] = {8, 3};
    myArrayOfPairs[3] = {1, 777};

    for (int i = 0; i < n; i++) {
        cout << myArrayOfPairs[i].first << " " << myArrayOfPairs[i].second << endl;
    }

    vector <int> myArrayOfVectors[n];

    for (int i = 0; i < n; i++) {
        myArrayOfVectors[i] = {2, 5, i};
    }
    myArrayOfVectors[1] = {5, 1, 2};

    for (int i = 0; i < n; i++) {
        for (auto itr = myArrayOfVectors[i].begin(); itr != myArrayOfVectors[i].end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    }

    sort(myArrayOfVectors, myArrayOfVectors + n);

    for (int i = 0; i < n; i++) {
        for (auto itr = myArrayOfVectors[i].begin(); itr != myArrayOfVectors[i].end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    }

    cout << *min_element(myArray, myArray + n) << endl;



    int i = 0;

    vector <int> myVector;

    myVector.push_back(4);

    myVector.erase(find(myVector.begin(), myVector.end(), 4));

    for (auto itr = myVector.begin(); itr < myVector.end(); ++itr) {
        cout << *itr << " ";
    }


    int a = 2;

   // cout << ceil(2);

    cout << *min_element(myVector.begin(), myVector.end()) << endl;

    return 0;
    */
     return 0;
}
