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
    int lengthLongestWord = 0;
    string longestWord;
    string prevword;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && s[i - 1] != ' ') {
            numSpaces++;
            if (lengthLongestWord < cnt) {
                lengthLongestWord = cnt;
                longestWord = prevword;
                cnt = 0;
                prevword = "";
            }

        } else {
            cnt++;
            prevword += s[i];
        }
    }

   // cout << "The longest word  " << numSpaces + 1 << " words in this string." << endl;
   cout << longestWord << " " << lengthLongestWord;
}
/*void solve() {
    string s;
    int ans = 0;
    while (cin >> s) {
        ans++;
    }
    cout << ans;
}
 */
int main() {
    string s;
    cout << "Enter phrase: ";
    getline(cin, s);
    cout << endl;

    countWords(s);
//    solve();

    return 0;
}
