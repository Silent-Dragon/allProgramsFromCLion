#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;


int main() {
    //first test with normal value -- iterator
    vector <int> myVector;
    myVector.push_back(5);
    myVector.push_back(88);
    myVector.push_back(2);

    for (auto itr : myVector) {
        cout << itr << " ";
    }
    cout << endl;

    //second test with pair value -- iterator
    vector <pair <int, int>> myVector2;
    myVector2.push_back({5, 9});
    myVector2.push_back({88, 33});
    myVector2.push_back({2, 76});

    for (auto itr : myVector2) {
        cout << itr.first << " ";
        cout << itr.first << " ";
    }
    cout << endl;

    //third test with pair value -- pointer
    vector <pair <int, int>> myVector3;
    myVector3.push_back({5, 9});
    myVector3.push_back({88, 33});
    myVector3.push_back({2, 76});

    for (auto pointer = myVector3.begin(); pointer != myVector3.end(); pointer++) {
        //first way
        cout << pointer->first << " ";
        cout << pointer->second << endl;

        //second way
        cout << (*pointer).first << " ";
        cout << (*pointer).second << endl;
    }
    cout << endl;

    //fourth test with normal value -- pointer
    vector <int> myVector4;
    myVector4.push_back(5);
    myVector4.push_back(88);
    myVector4.push_back(2);

    for (auto pointer = myVector4.begin(); pointer != myVector4.end(); pointer++) {
        //first way
        cout << *pointer << endl;

        //second way
        cout << (*pointer) << endl;
    }
    cout << endl;

    return 0;
}