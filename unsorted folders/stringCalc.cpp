#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

string n;


int calculator(string n) {
    if (n.size() == 0) {
        cout << "Empty" << endl;
        return 0;
    }

    if (n.size() == 1) {
        cout << n << endl;
        return stoi(n);
    } else {
        for (int i = 0; i < n.size(); i++) {
            char c = n[i];
            if (c != ",") {
                cout << n[i] << endl;
            }
        }
    }


    return 0;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    calculator(n);

    return 0;
}
