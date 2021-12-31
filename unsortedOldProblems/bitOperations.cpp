#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    //XOR
    int XOR;
    XOR = n ^ m;
    //XOR = n xor m; longer

    cout << XOR << endl;

    //OR
    int OR;
    OR = n | m;
    //OR = n or m; longer

    cout << OR << endl;

    //AND
    int AND;
    AND = n & m;
    //AND = n and m; longer

    cout << AND << endl;

    return 0;
}