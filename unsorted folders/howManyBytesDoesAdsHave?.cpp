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

const int N = (int)2e5 + 7;
//const int K = (int)1e9 + 7;
const int LOG = 30; //of K
const int modulo = (int)1e9 + 7;

int n;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    //sizeof() gets size

    //int array of size n
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Please input place " << i << " of the int array ";
        cin >> a[i];
    }
    cout << "Size of int array in bytes is " << sizeof(a) << endl;

    //char array of size n
    char a2[n];
    for (int i = 0; i < n; i++) {
        cout << "Please input place " << i << " of the char array ";
        cin >> a2[i];
    }
    cout << "Size of char array in bytes is " << sizeof(a2) << endl;

    //int vector of size n
    vector <int> v;
    for (int i = 0; i < n; i++) {
        int number = 0;

        cout << "Please input place " << i << " of the int vector ";
        cin >> number;

        v.insert(number);
    }
    cout << "Size of int vector in bytes is " << sizeof(v) << endl;

    //char vector of size n
    vector <char> v2;
    for (int i = 0; i < n; i++) {
        char letter = 0;

        cout << "Please input place " << i << " of the char vector ";
        cin >> letter;

        v2.insert(letter);
    }
    cout << "Size of char vector in bytes is " << sizeof(v2) << endl;

    //int vector of size n
    set< int> s;
    for (int i = 0; i < n; i++) {
        int number2 = 0;

        cout << "Please input place " << i << " of the int set ";
        cin >> number2;

        s.insert(number2);
    }
    cout << "Size of int vector in bytes is " << sizeof(s) << endl;

    return 0;
}