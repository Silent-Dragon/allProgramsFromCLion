#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int reverse(int n) {
    int revNum = 0;

    while (n > 0) {
        revNum = revNum * 10 + n % 10;
        n = n / 10;
    }
    return revNum;
}

void makeNewNumber(string n) {
    int lengthN = n.length();

    int firstHalf = 0;
    int secondHalf = 0;

    if (lengthN == 2) {
        for (int i = 0; i < lengthN; i++) {
            if (i < lengthN / 2) {
                firstHalf = firstHalf * 10 + (n[i] - '0');
            } else {
                secondHalf = secondHalf * 10 + (n[i] - '0');
            }
        }


        if (firstHalf == reverse(secondHalf)) {
            cout << "2 and equal: " << firstHalf << secondHalf << endl;
        } else if (firstHalf < reverse(secondHalf)) {
            cout << "2 and smaller: " << firstHalf + 1 << reverse(firstHalf + 1) << endl;
        } else if (firstHalf > reverse(secondHalf)) {
            cout << "2 and bigger: " << firstHalf << reverse(firstHalf) << endl;
        } else {
            cout << "2 and error." << endl;
        }

        exit(0);
    }


    if (lengthN % 2  == 0) {
        for (int i = 0; i < lengthN; i++) {
            if (i < lengthN / 2) {
                cout << i << " " << lengthN << endl;
                firstHalf = firstHalf * 10 + (n[i] - '0');
            }
            if (i >= lengthN/2) {
                secondHalf = secondHalf * 10 + (n[i] - '0');
            }
        }

        cout << firstHalf << endl;
        cout << secondHalf << endl;

        if (firstHalf == reverse(secondHalf)) {
            cout << firstHalf << secondHalf << endl;
        } else if (firstHalf < reverse(secondHalf)) {
            cout << firstHalf + 1 << reverse(firstHalf + 1) << endl;
        } else if (firstHalf > reverse(secondHalf)) {
            cout << "Even and bigger: " << firstHalf << reverse(firstHalf) << endl;
        } else {
            cout << "Even and error." << endl;
        }

    } else {
        for (int i = 0; i < lengthN; i++) {
            if (i <= lengthN / 2) {
                firstHalf = firstHalf * 10 + (n[i] - '0');
            }
            if (i >= lengthN / 2) {
                secondHalf = secondHalf * 10 + (n[i] - '0');
            }
        }

        cout << firstHalf << endl;
        cout << secondHalf << endl;


        if (firstHalf == reverse(secondHalf)) {
            cout << "Odd and equal: " << firstHalf << reverse(firstHalf/10) << endl;
        } else if (firstHalf < reverse(secondHalf)) {
            cout << "Odd and smaller: " << firstHalf + 1 << reverse((firstHalf + 1) / 10) << endl;
        } else if (firstHalf > reverse(secondHalf)) {
            cout << "Odd and bigger: " << firstHalf << reverse(firstHalf/10) << endl;
        } else {
            cout << "Odd and error." << endl;
        }
    }


}


int main() {
    string n;
    cin >> n;

    int a[n.length()];

    for (int i = 0; i < n.length(); i++) {
        a[i] = string[i] - 'A' + 1;
    }

    int a[n.length() - 1] =


    makeNewNumber(n);

    return 0;
}