#include <iostream>
#include <algorithm>

using namespace std;

int n;
int main() {
    cout << "Enter number of chars in char array: ";
    cin >> n;
    cout << endl;

    char a[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter char for place " << i << " in char array: ";
        cin >> a[i];
        cout << endl;
    }

    string s;
    for (int i = 0; i < n; i++) {
        s += a[i];
        // s.push_back(a[i]); for array to vector conversion
    }
    cout << s;
    cout << endl;
}
