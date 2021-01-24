#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <cstdio>
#include <stdio.h>

using namespace std;

int n, currentCowMilkValue;
string currentCowName;

map <string, int> milkForEachCowInput;
set <int> milkForEachCow;

int main() {
    freopen ("notlast.in","r",stdin);
    freopen ("notlast.out","w",stdout);

    ///init
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> currentCowName >> currentCowMilkValue;

        a[i] = currentCowName;

        milkForEachCowInput[currentCowName] += currentCowMilkValue;
    }

    for (int i = 0; i < n; i++) {
        milkForEachCow.insert(milkForEachCowInput[a[i]]);
    }

    ///output
    int answerMilk = *++milkForEachCow.begin();
    for (auto iterator = milkForEachCowInput.begin(); iterator != milkForEachCowInput.end(); ++iterator) {
        if (iterator->second == answerMilk) {
            cout << iterator->first << endl;
            break;
        }
    }

    return 0;
}