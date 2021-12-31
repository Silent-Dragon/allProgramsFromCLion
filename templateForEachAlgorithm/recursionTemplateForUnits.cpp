#include <iostream>
#include <algorithm>

using namespace std;

int a;

int b, x; //B can be used if there is an aim target and X can be used for a constraint

int cnt; //Counter

int recursiveFunction(int n) {
    cnt++;
    //Let's say I want to get to a target and I have a constraint by going up, which is X
    if (n == b) {
        cout << "Reached target in " << cnt << " steps" << endl;
    }

    if (n + x <= b) {
        recursiveFunction(n + x);
    } else if (n * x <= b) {
        recursiveFunction(n * x);
    } else {
        return;
    }
}

int main() {
    cin >> a >> b;

    recursiveFunction(a);

    //number of ways to reach target
    cout << cnt << endl;

    //need to add min/max way to reach target
}
