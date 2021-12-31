#include <iostream>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int main() {

    string s;
    bool b = false;
    int cnt = 0;

    cin >> s;
    char pc = s[0];

    //s.size() <= 100

    /*
    while ((int) s.size() > 100) {
        cout << "Error, please submit a shorter sequence of players.";
        cin >> s;
    }*/

    //       .
    // 1111111
    for (int i = 0; i < (int) s.size(); i++) {
        // cnt = 6
        if (s[i] != pc) {
            cnt = 1;
            pc = s[i];
        } else {
            cnt++;
            pc = s[i];

            if (cnt == 7) {
                b = true;
            }
        }
    }

    if (b) {
        cout << "YES";
    } else {
        cout << "NO";
    }


}