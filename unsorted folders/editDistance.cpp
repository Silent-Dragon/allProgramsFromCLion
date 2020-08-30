#include<iostream>
#include<string>

using namespace std;

int minEditDistance(string start, string end, int len1, int len2) {
    int i, j;

    //create a matrix of order (len1+1)*(len2+1) to memoize values
    int edit[len1 + 1][len2 + 1];

    //edit[i][j] = minimum number of edit operations required to transform src[0....(i-1)] to dest[0...(j-1)]

    //initializing
    for (i = 0; i <= len1; i++) {
        edit[i][0] = i;  //min operations required to transform src[0...i-1] to empty dest string
    }

    for (j = 0; j <= len2; j++) {
        edit[0][j] = j;   //min operations required to transform empty src to dest[0...j-1]
    }

    //now, start filling the matrix row wise
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            //if current character of both strings match
            if (start[i - 1] == end[j - 1]) {
                edit[i][j] = edit[i - 1][j - 1];
            } /*mismatch*/ else {
                //try applying all operations and choose the one which costs minimum
                int x = 1 + edit[i - 1][j];    //delete
                int y = 1 + edit[i][j - 1];    //insert
                int z = 1 + edit[i - 1][j - 1];  //replace

                edit[i][j] = min(x, min(y, z));

            }
        }
    }

    //now, return the final value
    return edit[len1][len2];

}


int main() {
    string s;
    string e;

    cin >> s >> e;

    int len1 = s.length();
    int len2 = e.length();

    cout << minEditDistance(s, e, len1, len2);
    return 0;
}