#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

string firstRow = " ";
vector <char> currentRow;
vector <char> nextRow;

void generateNextRow() {
    //cout << "Check";

    if (currentRow.size() == 1) {
        for (int i = 0; i < currentRow.size(); i++) {
            cout << currentRow[i];
            cout << endl;
            return;
        }
    }

    for (int i = 0; i < currentRow.size() - 1; i++) {
        if (currentRow[i] == currentRow[i + 1]) {
            nextRow.push_back(currentRow[i]);
        } else if ((currentRow[i] == 'R' && currentRow[i + 1] == 'B') || (currentRow[i] == 'B' && currentRow[i + 1] == 'R')) {
            nextRow.push_back('G');
        } else if ((currentRow[i] == 'R' && currentRow[i + 1] == 'G') || (currentRow[i] == 'G' && currentRow[i + 1] == 'R')) {
            nextRow.push_back('B');
        } else {
            nextRow.push_back('R');
        }
    }


    currentRow.clear();
    //memset(&currentRow, ' ', sizeof(currentRow));
    for (int i = 0; i < nextRow.size(); i++) {
        currentRow.push_back(nextRow[i]);
    }
    nextRow.clear();

    generateNextRow();
}

int main() {
    cin >> firstRow;

    for (int i = 0; i < firstRow.length(); i++) {
        currentRow.push_back(firstRow[i]);
        cout << currentRow[i] << " ";
    }
    cout << endl;

    generateNextRow();

    return 0;
}