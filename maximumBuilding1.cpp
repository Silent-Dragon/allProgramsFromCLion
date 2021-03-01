#include<bits/stdc++.h>

using namespace std;

stack<int> myStack;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];

    int mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char inputChar;
            cin >> inputChar;
            if (inputChar == '.') a[j]++;
            else a[j] = 0;
        }

        for (int j = 0; j <= m; j++) {
            while (!myStack.empty() && a[myStack.top()] > a[j]) {
                int top = myStack.top();
                myStack.pop();
                int area = a[top] * (myStack.empty() ? j : j - myStack.top() - 1);
                mx = max(mx, area);
            }

            if (j < m) {
                myStack.push(j);
            }
        }
    }

    cout << mx << endl;
}