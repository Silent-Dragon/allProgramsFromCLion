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
    queue <int> myQueue;

    ///insertion
    myQueue.push(63);
    myQueue.push(5);
    myQueue.push(987);
    myQueue.push(2);
    myQueue.push(41);

    ///iterating and printing
    queue <int> myQueueCopy = myQueue;
    while (!myQueueCopy.empty()) {
        cout << myQueueCopy.front() << " ";
        myQueueCopy.pop();
    }
    cout << endl;

    ///start and end
    cout << myQueue.front() << " " << myQueue.back() << endl;

    ///min and max not possible

    ///not sorting

    ///find by key or value not possible

    ///upper-lower bound not possible

    ///deletion
    myQueue.pop();

    ///clear not possible

    return 0;
}
