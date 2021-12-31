#include <bits/stdc++.h>
using namespace std;

stack <int> myStack;
int n;

int main () {
    cout << "Enter size of stack ";
    cin >> n;

    int input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];

        myStack.push(input[i]);
    }

    for (auto itr : myStack) {
        cout << itr << " ";
    }
    cout << endl;

    cout << "First item in stack is " << myStack.top() << endl;

    cout << "Removing first item in stack" << endl;
    myStack.pop();

    for (auto itr : myStack) {
        cout << itr << " ";
    }
    cout << endl;

    cout << "First item in stack is " << myStack.top() << endl;
    cout << "Size of stack is " << myStack.size() << endl;

    return 0;
} 
