#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

struct data {
    int number, number2;
};

// comparator
bool cmp(data a, data b) {
/*
a = (3, 5)
b = (3, 4)
*/
    if (a.number != b.number) {
        return a.number < b.number;
    }
    else {
        /*
        if (a.number2 < b.number2) return 1;
        else return 0;*/
        return a.number2 < b.number2;
    }
}
/*
    (1, 3)
    (2, 4)
    (2, 1)

    (1, 3)
    (2, 1)
    (2, 4)
*/

int main() {

    data a[3];
    int x;

    cin >> a[0].number;
    cin >> a[1].number;
    cin >> a[2].number;

    sort(a, a + 3, cmp);

    for (int i = 0; i < 3; i++) {
        cout << a[i].number << " " << a[i].number2 << endl;
    }
}
