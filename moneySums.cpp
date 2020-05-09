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

long long int was[100001][101];

int coinCombinations(int i, int a[], int aggregatedCombination) {
   // cout << "Created " << aggregatedCombination << " at place (" << i << ")" << endl;

    if (was[aggregatedCombination]) {
       //cout << "Already was at " << aggregatedCombination << endl;
        return 0;
    }
    was[aggregatedCombination] = 1;

    for (int j = i + 1; j < n; j++) {
        //cout << "Trying to match " << aggregatedCombination << " with " << a[j] << endl;
        coinCombinations(j, a, aggregatedCombination + a[j]);
    }

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

    for (int i = 0; i < n; i++) {
        coinCombinations(i, a, a[i]);
    }
    cout << results.size() << endl;

    set <int>::iterator itr;
    for (itr = results.begin(); itr != results.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}
