#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

bool isDigit(char n) {

    bool flag = false;

    char numbers[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};



    for (int i = 0; i < 9; i++) {
       // cout << numbers[i];
        if (n == numbers[i]) {
            flag = true;
        }
    }

    return flag;

}



int main() {

    int r = 1;
    int c = 4;
    char myMaze[1000][1000];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
           cin >> myMaze[i][j];
        }
    }


    for (int i = 0; i < r; i++) { // 7 8 5 4       ----   0 1 2 3
        for (int j = 0; j < c; j++) {
            cout << "Inside myMaze looking at value: ";
            cout << myMaze[i][j];
            cout << endl;
            if (myMaze[i][j] == 'S') {
                cout << "My starting point in myMaze is: " << i << ", " << j;
                cout << endl;
                //myPath(i, j, 0);
            }
        }
    }

    cout << "Hello";

    return 0;
}
