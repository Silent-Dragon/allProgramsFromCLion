#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int countDigit(int n) {
    int count = 0;
    while (n != 0) {
        n = n / 10;
        count++;
    }
    return count;
}



int reverse(int n) {
    int revNum = 0;

    while (n > 0) {
        revNum = revNum * 10 + n % 10;
        n = n / 10;
    }
    return revNum;
}

void makeNewNumber(int n) {
    int lengthN = countDigit(n);
    string s = to_string(n);

    string firstHalfString = "";
    string secondHalfString = "";


    int firstHalf = 0;
    int secondHalf = 0;
    int currentInputPalindrome = 0;

    if (lengthN % 2  == 0) {
        for (int i = 0; i < lengthN; i++) {
            if (i < lengthN / 2) {
                firstHalf = firstHalf * 10 + (s[i] - '0');
            }
            if (i >= lengthN/2) {
                secondHalf = secondHalf * 10 + (s[i] - '0');
            }
        }

        currentInputPalindrome = firstHalf * pow(10, lengthN/2) + reverse(firstHalf);

        if (n < currentInputPalindrome) {
            cout << firstHalf << reverse(firstHalf) << endl;
        } else {
            cout << firstHalf + 1 << reverse(firstHalf + 1) << endl;
        }

    } else {
        for (int i = 0; i < lengthN; i++) {
            if (i <= lengthN / 2) {
                firstHalf = firstHalf * 10 + (s[i] - '0');
            }
            if (i >= lengthN / 2) {
                secondHalf = secondHalf * 10 + (s[i] - '0');
            }
        }

        currentInputPalindrome = firstHalf * pow(10, lengthN/2) + reverse(firstHalf);

        if (n < currentInputPalindrome) {
            cout << firstHalf << reverse(firstHalf / 10) << endl;
        } else {
            cout << firstHalf + 1 << reverse((firstHalf + 1) / 10);
        }
    }


}


int main() {
    int n;

    cin >> n;

    makeNewNumber(n + 1);

    return 0;
}