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

int main() {
    ///init
    queue <pair <int, pair <int, int>>> myQueue;

    ///insertion
    myQueue.push({63, {5, 76}});
    myQueue.push({1, {15, 843}});
    myQueue.push({22, {395, 97}});
    myQueue.push({4444, {888, 654}});
    myQueue.push({989, {21, 34}});

    ///iterating and printing
    queue <pair <int, pair <int, int>>> myQueueCopy = myQueue;
    while (!myQueueCopy.empty()) {
        cout << myQueueCopy.front().first << " ";
        cout << myQueueCopy.front().second.first << " ";
        cout << myQueueCopy.front().second.second << ", ";
        myQueueCopy.pop();
    }
    cout << endl;

    ///start and end
    cout << myQueue.front().first << " " << myQueue.back().first << endl;

    ///min and max not possible

    ///not sorting

    ///find by key or value not possible

    ///upper-lower bound not possible

    ///deletion
    myQueue.pop();

    ///clear not possible

    return 0;
}
