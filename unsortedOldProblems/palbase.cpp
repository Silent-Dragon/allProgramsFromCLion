#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int curBase = 2;
vector <int> digits;

int ToBaseB(int n, int b, vector <int> digits) {

     while (n != 0) {
         digits.push_back(n % b);
         n /= b;
     }
     reverse (digits.begin(), digits.end());

}

bool isPalindrome(char str[]) {
    int n = strlen(str);

    if (n == 0) {
        return true;
    }

    //return isPalRec(str, 0, n - 1);
}

void check(int n) {
    ToBaseB(n, curBase, digits);

    char string[] = "";

    for (int i = 0; i < sizeof(digits); i++) {

    }

    if (isPalindrome(digits)) {
        cout << curBase << endl;
        curBase = 2;
        exit(0);
    } else {
        curBase++;
        check(n);
    }
}


bool isPalRec(char str[], int s, int e){

    if (s == e) {
        return true;
    }

    if (str[s] != str[e]) {
        return false;
    }

    if (s < e + 1) {
        return isPalRec(str, s + 1, e - 1);
    }

    return true;
}









int main() {

    int t = 0;
    cout << "Input number of test cases:";
    cin >> t;
    cout << endl;


    int a[t];
    for (int i = 0; i < t; i++) {
        cout << "Input value in index " << i << " in the array: ";
        cin >> a[i];
    }

    for (int i = 0; i < t; i++) {
        check(a[i]);
    }

    return 0;
}