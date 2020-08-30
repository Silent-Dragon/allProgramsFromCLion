#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

string code1;
string code2;

int sum1;
int sum2;
int cnt;

map <int, int> results;


void pr() {

//this is for getting the sum of the first string
    for (int i = 0; i < strlen(code1); i++) {
        if (code1[i] == "+") {
            sum1 += 1;
        } else {
            sum1 -= 1;
        }
    }

    bool qmIteratingHelper[strlen(code2)];

//This is for scanning and checking the number of ?s and then putting the true and false places in the array
    for (int i = 0; i < strlen(code2); i++) {
        if (code2[i] == "?") {
            cnt++;
            qmIteratingHelper[i] == 1;
        } else {
            qmIteratingHelper[i] == 0;
        }
    }
/*
    normal string + - ? ? -


    + - + + -
    + - + - -
    + - - + -
    + - - - -



    question mark iterating helper false, false. true, true, false

  */

    for (int a = 0; a < cnt; a++) {

        for (int i = 0; i < strlen(code2); i++) {
            if (code2[i] == '?') {
                if (qmIteratingHelper[i]) {
                    sum2 += 1;
                    qmIteratingHelper[i] == 0;
                } else {
                    sum2 -= 1;
                }
                // if (question mark iterating helper (i) is true)
                //   then
                //   do plus and set question mark iterating helper (i) = false)
                //   else
                //   do minus
            } else if (code2[i] == "+") {
                sum2 += 1;
            } else {
                sum2 -= 1;
            }
        }
    }

}

int main() {
    cin >> code1;
    cin >> code2;

    pr();


    return 0;
}
