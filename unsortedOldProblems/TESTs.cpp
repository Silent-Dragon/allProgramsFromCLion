#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

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







