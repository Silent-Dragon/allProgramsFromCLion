#include <iostream>
#include <stack>

using namespace std;

///vector can be used instead of stack

int main() {
    ///init
    stack <int> myStack;

    ///insert
    myStack.push(5); ///adds 5 to the back of the stack
    myStack.push(4);
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);

    ///iterating and printing value
    stack <int> myStack2 = myStack;

    ///only way to iterate through the stack and print its values is by making a copy and printing
    ///the last item in the stack and then removing it as we loop through the stack
    while (!myStack2.empty()) {
        cout << myStack2.top() << " "; ///prints the last item in the list
        myStack2.pop(); ///removes the last item so that we can go to the next item of the stack
                        ///in the next iteration of the loop
    }
    cout << endl;

    ///erase
    myStack.pop(); ///removes last added item

    ///end, cannot print first item
    cout << "printing the last added item in myStack: " << myStack.top() << endl;

    ///find
    int wantedValue = 4;
    stack <int> myStack3 = myStack;

    ///only way to find value is to iterate through the stack and print its values is by making a copy and printing
    ///the last item in the stack and then removing it as we loop through the stack
    while (!myStack3.empty()) {
        if (myStack3.top() == wantedValue) {
            cout << myStack3.top() << " is the wanted value and has been found." << endl;
            break;
        } else {
            cout << myStack3.top() << " is not the wanted value." << endl;
        }
        myStack3.pop(); ///removes the last item so that we can go to the next item of the stack
        ///in the next iteration of the loop
    }
    cout << endl;

    ///clear
    ///you would need to iterate through the stack and remove all the items
    while (!myStack.empty()) {
        myStack.pop();
    }

    return 0;
}