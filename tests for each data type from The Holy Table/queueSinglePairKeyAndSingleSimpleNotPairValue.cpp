#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <queue>

using namespace std;

///THIS WILL DEMONSTRATE THE TWO WAYS THAT THIS CAN BE DONE.
///FIRST IS WITH A 2D QUEUE
///SECOND IS WITH A MAP

int main() {
    ///FIRST IMPLEMENTATION WITH 2D QUEUE

    ///init
    int n = 5;
    queue <int> myQueue[n][n];

    ///insertion
    myQueue[0][1].push(63);
    myQueue[3][1].push(5);
    myQueue[2][0].push(987);
    myQueue[4][4].push(2);
    myQueue[4][2].push(41);

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           // cout << myQueue[i][j].front() << " ";
           //DOES NOT WORK
        }
    }
    cout << endl;

    ///start and end
    cout << myQueue[0][1].front() << myQueue[0][1].back() << endl;

    ///min and max not possible

    ///not sorting

    ///find by key or value not possible

    ///upper-lower bound not possible

    ///deletion
    myQueue[0][1].pop();

    ///clear not possible

    ///SECOND IMPLEMENTATION WITH A MAP

    ///init
    map <pair <int, int>, queue <int>> myQueue2;

    ///insertion
    myQueue2[{0, 1}].push(63);
    myQueue2[{3, 1}].push(5);
    myQueue2[{2, 0}].push(987);
    myQueue2[{4, 4}].push(2);
    myQueue2[{0, 1}].push(41);

    ///iterating and printing
    for (auto itr = myQueue2.begin(); itr != myQueue2.end(); itr++) {
        cout << itr->second.front() << " ";
    }
    cout << endl;

    ///start and end
    cout << myQueue2[{0, 1}].front() << " " << myQueue2[{0, 1}].back() << endl;

    ///min and max not possible

    ///not sorting

    ///find by key or value not possible

    ///upper-lower bound not possible

    ///deletion
    myQueue2[{0, 1}].pop();

    ///clear not possible

    return 0;
}
