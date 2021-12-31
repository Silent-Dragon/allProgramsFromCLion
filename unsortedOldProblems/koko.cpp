#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int speed(double k, vector <int> a) {

    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += ceil(a[i]/k);
    }

    return sum;
}


int main(){

    int h;
    cout << "Input number of hours before the guards come back: ";
    cin >> h;

    cout << endl;

    int n;
    cout << "Input number of items in array: ";
    cin >> n;

    cout << endl;

    vector <int> piles(n);
    for (int i = 0; i < n; i++){
        cout << "Input value for index " << i << " in array: ";
        cin >> piles[i];
    }

    cout << endl;
    //int sizeOfArray = sizeof(piles)/ sizeof(piles[0]);

    int l = 1;
    int r = 1e9;
    int ans = 0;


    for (int i = 1; i <= n; i++) {
        cout << speed(i, piles) << endl;
    }

    while (l <= r) {

        int m = l + (r - l) / 2;

        if (h < speed(m, piles)) {
            l = m + 1;
        } else {
            r = m - 1;
            ans = m;
        }
    }

    cout << "Eating speed is: " << ans << endl;

   return -1;




}

