#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << endl;

    char a[s.size()];
    for (int i = 0; i < s.size(); i++) {
        a[i] = s[i];
        cout << a[i] << ' ';
    }
    cout << endl;
}
