#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int diagonalIteration(int startingI, int startingJ) {
    int n = 4;
    //example size of board
    vector <int> diag1;
    // for diagonal lines with sum
    vector <int> diag2;
    //for diagonal lines with difference

    for (int i = 0; i < diag1.size(); i++) {
        if (diag1[i] == startingI + startingJ) {
            cout << "Place for queen is taken in diag1." << endl;
            return false;
        }
    }

    for (int i = 0; i < diag2.size(); i++) {
        if (diag2[i] == startingI - startingJ) {
            cout << "Place for queen is taken in diag2." << endl;
            return false;
        }
    }

    cout << "Place for queen passes both tests." << endl;
    diag1.push_back(startingI + startingJ);
    diag2.push_back(startingI - startingJ);

    return true;
}


int main() {

    diagonalIteration(2,3);
    //example place of queen

}