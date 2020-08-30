#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>


using namespace std;

int main(){

    int n;
    int cnt = 0;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number for place " << i << " in the array: " << endl;
        cin >> a[i];
    }

    cout << endl;

    map <int, int> m;

    for (int i = 0; i < n; i++) {
        m[a[i]] = m[a[i]] + 1;
        cout << m[a[i]] << endl;
    }



    for (auto it = m.begin(); it != m.end(); it++) {
            cout << "Entering for loop." << endl;
        if (it->second != it->first) {
            cout << "Key is not equal to value." << endl;
            if (it->second < it->first) {
                cnt += it->second;
                cout << "Value is smaller than key and cnt is " << cnt << endl;
            } else {
                cnt += it->second - it->first;
                cout << "Value is bigger than key and cnt is " << cnt << endl;
            }
        }
    }

    cout << "Number of moves needed: " << cnt << endl;

}

