#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

int b;
int d;

void noReference(int a) {
    a = 100; //this should not be changed outside of function
    b = a + 1; //this will be changed outside of function
}

void reference(int &c) {
    c = 100; //this should be changed outside of function
    d = c + 1; //this will be changed outside of function
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int inputA, inputC;

    cout << "Inputs: ";
    cin >> inputA >> inputC;

    noReference(inputA);
    reference(inputC);

    cout << "A is " << inputA << " and B is " << b << endl;
    cout << "C is " << inputC << " and D is " << d << endl;
}