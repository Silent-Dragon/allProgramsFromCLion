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

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    int dpPrices[x + 1];
    int dpPages[x + 1];
    int numberOfPages[n + 1];
    int prices[n + 1];
    //vector <int> coins;
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> numberOfPages[i];
    }

    for (int i = 1; i <= x; i++) {
        dpPages[i] = 0;
        dpPrices[i] = 0;
    }

    dpPrices[0] = 0;
    dpPrices[0] = 1;
    dpPages[0] = 0;
    dpPages[0] = 1;

    for (int j = 1; j <= x; j++) {
        for (int i = 0; i < n; i++) {
            if (j - prices[i] >= 0) {
                dpPrices[j] = (dpPrices[j] + dpPrices[j - prices[i]]) % (int)(1e9 + 7);
                dpPages[j] = (dpPages[j] + dpPages[j - prices[i]]) % (int)(1e9 + 7); //now we need to know the book that was used?

            }
        }
    }


    cout << dpPages[x] << endl;

    return 0;
}