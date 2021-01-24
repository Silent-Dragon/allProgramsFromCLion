#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <math.h>

using namespace std;

long long int a[1005];
long long int n, m, mx;
stack <int> myStack;

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char currentChar = ' ';
            cin >> currentChar;
            if (currentChar == '.') {
                a[j]++;
            } else {
                a[j] = 0;
            }
        }

        for (int j = 0; j <= m; j++) {
            while (!myStack.empty() && a[myStack.top()] > a[j]) {
                int top = myStack.top();
                myStack.pop();

                int area = a[top] * (j - myStack.top() - 1);
                mx = max(mx, area);
            }
            if (j < m) {
                myStack.push(j);
            }
        }
    }
    cout << mx << endl;
}