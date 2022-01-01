#include<iostream>
#include<string>

using namespace std;

int minEditDistance(string start, string end, int lengthOfStartString, int lengthOfEndString) {
    //create a matrix of order (lengthOfStartString+1)*(lengthOfEndString+1) to memoize values
    int edit[lengthOfStartString + 1][lengthOfEndString + 1];
    //edit[i][j] = minimum number of edit operations required to transform src[0....(i-1)] to dest[0...(j-1)]

/// Init
    int i, j;
    for (i = 0; i <= lengthOfStartString; i++) {
        edit[i][0] = i;  //min operations required to transform src[0...i-1] to empty dest string
    }

    for (j = 0; j <= lengthOfEndString; j++) {
        edit[0][j] = j;   //min operations required to transform empty src to dest[0...j-1]
    }

    //now, start filling the matrix row wise
    for (i = 1; i <= lengthOfStartString; i++) {
        for (j = 1; j <= lengthOfEndString; j++) {
            //if current character of both strings match
            if (start[i - 1] == end[j - 1]) {
                edit[i][j] = edit[i - 1][j - 1];
            } /*mismatch*/ else {
                //try applying all operations and choose the one which costs minimum
                int deleteOperation = 1 + edit[i - 1][j];       //delete
                int insertOperation = 1 + edit[i][j - 1];       //insert
                int replaceOperation = 1 + edit[i - 1][j - 1];  //replace

                edit[i][j] = min(deleteOperation, min(insertOperation, replaceOperation));
            }
        }
    }

    //now, return the final value
    return edit[lengthOfStartString][lengthOfEndString];

}


int main() {
    string string1;
    string string2;

    cin >> string1 >> string2;

    int lengthOfStartString, lengthOfEndString;
    lengthOfStartString = string1.length();
    lengthOfEndString = string2.length();

    cout << minEditDistance(string1, string2, lengthOfStartString, lengthOfEndString);
    return 0;
}