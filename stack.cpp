#include <iostream>
#include <stack>

using namespace std;

int n;
stack <int> myStack;

int main() {

    cin >> n;

    int input[n];
    for (int i = 0; i < n; i++) {
        cout << "Input place " << i + 1 << " in your stack";
        cin >> input[i];

        myStack.push(1);
        cout << endl;
    }


}