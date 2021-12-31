#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

bool isItDigit(unsigned char c) {

    if(isdigit(c)) {
        return true;
    } else {
        return false;
    }

}

int main() {
    char c;
    cin >> c;

    if(isItDigit(c)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}