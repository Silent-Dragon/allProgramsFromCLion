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
    queue <pair <int, pair <int, int>>> myQueue[n][n];

    ///insertion
    myQueue[0][1].push({63, {2, 72}});
    myQueue[3][1].push({5, {8214, 389}});
    myQueue[2][0].push({11, {6, 987}});
    myQueue[4][4].push({2, {278, 56}});
    myQueue[4][2].push({41, {9, 934}});

    ///iterating and printing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // cout << myQueue[i][j].front().first << " ";
            // cout << myQueue[i][j].front().second << " ";
            //DOES NOT WORK
        }
    }
    cout << endl;

    ///start and end
    cout << myQueue[0][1].front().first << myQueue[0][1].back().second.second << endl;

    ///min and max not possible

    ///not sorting

    ///find by key or value not possible

    ///upper-lower bound not possible

    ///deletion
    myQueue[0][1].pop();

    ///clear not possible

    ///SECOND IMPLEMENTATION WITH A MAP

    ///init
    map <pair <int, int>, queue <pair <int, pair <int, int>>>> myQueue2;

    ///insertion
    myQueue2[{0, 1}].push({63, {2, 72}});
    myQueue2[{3, 1}].push({5, {8214, 389}});
    myQueue2[{2, 0}].push({11, {6, 987}});
    myQueue2[{4, 4}].push({2, {278, 56}});
    myQueue2[{4, 2}].push({41, {9, 934}});

    ///iterating and printing
    for (auto itr = myQueue2.begin(); itr != myQueue2.end(); itr++) {
        cout << itr->second.front().first << " ";
        cout << itr->second.front().second.first << " ";
        cout << itr->second.front().second.second << " ";
    }
    cout << endl;

    ///start and end
    cout << myQueue2[{0, 1}].front().first << " " << myQueue2[{0, 1}].back().second.first << endl;

    ///min and max not possible

    ///not sorting

    ///find by key or value not possible

    ///upper-lower bound not possible

    ///deletion
    myQueue2[{0, 1}].pop();

    ///clear not possible

    return 0;
}