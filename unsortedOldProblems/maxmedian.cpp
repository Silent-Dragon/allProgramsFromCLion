#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;


int main() {


        int n = 0;
        int k = 0;
        int median = 0;

        cin >> n;

        /*
        while (n <= 1 || n >= 2 * 105) {
            cout << "Please input the number of items in the array: " << endl;
            cin >> n;
            if (n <= 1 || n >= 2 * 105) {
                cout << "Invalid input, please try again.";
            }
        }
    */

        cout << endl;
        cin >> k;

        /*
        while (k <= 1 || k >= 109) {
            cout << "Please enter the number of operations allowed: " << endl;
            cin >> k;
            if (k <= 1 || k >= 109) {
                cout << "Invalid input, please try again.";
                cin >> n;
            }
        }
    */
        cout << endl;



        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }



        while (k > 0) {
            sort(a, a + n);
            a[n / 2] += 1;
            k--;
        }

        sort(a, a + n);

        cout << a[n / 2];











}