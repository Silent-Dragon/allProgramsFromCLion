#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void pour(int& c1, int& m1, int& c2, int& m2) {
    int amount = min(m1, c2 - m2);
    m1 -= amount;
    m2 += amount;
}

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    //freopen("in.txt", "r", stdin);

    int c1, c2, c3;
    int m1, m2, m3;
    cin >> c1 >> m1;
    cin >> c2 >> m2;
    cin >> c3 >> m3;

    for (int i = 0; i < 33; i++) {
        pour(c1, m1, c2, m2);
        pour(c2, m2, c3, m3);
        pour(c3, m3, c1, m1);
    }

    pour(c1, m1, c2, m2);

    cout << m1 << endl << m2 << endl << m3 << endl;

    return 0;
}