#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;


int y, w, d;
string res = " ";

void pr() {

    int chances = 6 - max(y, w) + 1;

    switch(chances) {
        case 1:
            res = "1/6";
            break;
        case 2:
            res = "1/3";
            break;
        case 3:
            res = "1/2";
            break;
        case 4:
            res = "2/3";
            break;
        case 5:
            res = "5/6";
            break;
        default:
            res = "1/1";
    }

}



int main() {
    cout << "Enter the result of Yakko's throw: ";
    cin >> y;
    cout << endl;

    cout << "Enter the result of Wakko's throw: ";
    cin >> w;
    cout << endl;

    pr();

    cout << res;

}