#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

long long int n = 0;
long long int x = 0;

set <int> results;

bool was[100001][101]; // this helps in case with 5 8 3

int coinCombinations(int i, int a[], int aggregatedCombination) {
    if (i > n) {
        return 0;
    }

    // cout << "Created " << aggregatedCombination << " at place (" << i << ")" << endl;

    if (was[aggregatedCombination][i]) {
       //cout << "Already was at " << aggregatedCombination << endl;
        return 0;
    }
    was[aggregatedCombination][i] = 1;

    //cout << "Trying to match " << aggregatedCombination << " with " << a[j] << endl;
    coinCombinations(i + 1, a, aggregatedCombination + a[i]);
    coinCombinations(i + 1, a, aggregatedCombination);

    //cout << "Inserting " << aggregatedCombination << endl;
    results.insert(aggregatedCombination);
    return 1;
}


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int a[n + 1];
    //vector <int> coins;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    coinCombinations(0, a, 0);
    cout << results.size() - 1 << endl;

    set <int>::iterator itr;
    for (itr = results.begin(); itr != results.end(); itr++) {
        if (*itr != 0) {
            cout << *itr << " ";
        }
    }
    cout << endl;

    return 0;
}
