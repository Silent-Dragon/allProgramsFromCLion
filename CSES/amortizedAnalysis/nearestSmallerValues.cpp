/* Nearest Smaller Element Template */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int N = 1e8; //max n we can have

int n, a[N];
stack <int> nearestSmallerElements; //using a stack to store nearest smaller elements
//as stack removes and inserts items from the back ONLY in O(1) time
vector <int> ans; //using a vector to store our answer

void nearestSmallerElement() {
    for (int i = 0; i < n; i++) {
        while (!nearestSmallerElements.empty() && a[nearestSmallerElements.top()] >= a[i]) {
            nearestSmallerElements.pop(); //while the value in the array of the last element
            //in the stack is larger or equal to our current element in the array,
            //we will remove it
        }

        if (!nearestSmallerElements.empty()) {
            ans.push_back(nearestSmallerElements.top() + 1); //if the stack is not empty we can
            //use the last element in the stack as our answer
        } else {
            ans.push_back(0); //no valid answer for the current place in the array
        }

        nearestSmallerElements.push(i); //adding position of current value to the stack
        //so that it can be used to compare an answer for the next value/s
    }
}

int main() {
/// Input
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

/// Method
    nearestSmallerElement();

/// Output
    for (auto itr : ans) {
        cout << itr << " ";
    }
    cout << endl;
    return 0;
}