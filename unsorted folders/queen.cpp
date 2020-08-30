#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n;
int chessBoard[11][11];
// vector <int> chessBoard[n][n];//int chessBoard[n][n]
vector <int> diag1;
// for diagonal lines with sum
vector <int> diag2;
//for diagonal lines with difference

//we have our vectors here because if they are inside the function, they will be reset each iteration


int PossibleToPut(int startingI, int startingJ) {

    for (int i = 0; i < n; i++) {
        if (i == startingI) {
            for (int j = 0; j < n; j++) {
                if (chessBoard[startingI][j] == 1) {
                    return false;
                }
            }
        }
    }


    for (int j = 0; j < n; j++) {
        if (j == startingJ) {
            for (int i = 0; i < n; i++) {
                if (chessBoard[i][startingJ]) {
                    return false;
                }
            }
        }
    }




    for (int i = 0; i < (int)diag1.size(); i++) {
        if (diag1[i] == startingI + startingJ) {
            //cout << "Place for queen is taken in diag1." << endl;
            return false;
        }
    }

    // diag2.size()
    //cout << diag2.size() - 1 << endl;//

    for (int i = 0; i < (int)diag2.size(); i++) {
        if (diag2[i] == startingI - startingJ) {
            //cout << "Place for queen is taken in diag2." << endl;
            return false;
        }
    }

    //cout << "Place for queen passes both tests." << endl;
    diag1.push_back(startingI + startingJ);
    diag2.push_back(startingI - startingJ);

    return true;
}

//if a[i][j] == 1 it means this cell is not empty
void rec(int cnt) {
    if (cnt == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << chessBoard[i][j];
            }
            cout << endl;
        }
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (PossibleToPut(i, j)) {
                chessBoard[i][j] = 1;
                rec(cnt + 1);
                // i = 0, j = 0
                chessBoard[i][j] = 0;
                diag1.pop_back();
                diag2.pop_back();

            }
        }
    }
    return;
}


int main() {

    cin >> n;
    rec(0);
    cout << "Impossible";

}