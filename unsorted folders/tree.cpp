#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[101][101];
int m;

// n = number of vertices
// a = matrix -- NOTE: matrix cannot be declared as N,N at this stage because n is 0
// m = number of edges

void cnt() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                a[j][i] = 0;
                m++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //cout << "Value in place " << i << ", " << j << ": " << a[i][j];
            //cout << endl;
        }
    }

}

int main() {
    //cout << "Enter the number of vertices: ";
    cin >> n;
   //cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //cout << "Enter 0 or 1 for place " << i << ", " << j << ": ";
            cin >> a[i][j];
            //cout << endl;
        }
    }

    cnt();

    //cout << m;

    if (n == m + 1) {
        cout << "Yes";
    } else {
        cout << "NO";
    }

    return 0;
}
