#include <iostream>

using namespace std;

long long int n, m, testCases;

int main() {

    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        cin >> n >> m;
        if (n == 1) {
            cout << 0 << endl;
        } else if (n == 2) {
            cout << m << endl;
        } else { //n >= 3
            cout << m * 2 << endl;
        }
    }
}