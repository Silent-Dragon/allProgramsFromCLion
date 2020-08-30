#include <iostream>

using namespace std;

string s;
int main() {
    cin >> s;
    int n = 0;

    /*
    if (s[0] == '-') {
        for (int i = 1; i < s.size(); i++) {
            n = n * 10 + (s[i] - '0');
        }
        n = -n;
    }
    else {
        for (int i = 0; i < s.size(); i++) {
            n = n * 10 + (s[i] - '0');
        }
    }*/

    // cout << (n == 5) << endl;
    for (int i = 0 + (s[0] == '-'); i < s.size(); i++) {
        n = n * 10 + (s[i] - '0');
    }
    if (s[0] == '-') {
        n = -n;
    }


    cout << n + 1;
    /*
        3152

        '0' = 48
        '3' -> 51 - 48 = 3
        'a' = 65
        'b' = 66

        1)
            n = 0 * 10 + 3 = 3
        2)
            n = 3 * 10 + 1 = 31
        3)
            n = 31 * 10 + 5 = 315
        4)
            n = 315 * 10 + 2 = 3152

    */
    return 0;
}