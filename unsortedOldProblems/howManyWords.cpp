#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

void countWords(string s) {
    int numSpaces = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && s[i - 1] != ' ') {
            numSpaces++;
        }//s[i] == ' '
    }

    cout << "There are " << numSpaces + 1 << " words in this string." << endl;
}
void solve() {
    string s;
    int ans = 0;
    while (cin >> s) {
        ans++;
    }
    cout << ans;
}
int main() {
//    string s;
//    cout << "Enter phrase: ";
//    getline(cin, s);
//    cout << endl;

    solve();

    return 0;
}
