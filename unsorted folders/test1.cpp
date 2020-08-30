#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(&a[0], &a[n]);


    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl << a + 0 << endl;
    cout << a << endl;
}
