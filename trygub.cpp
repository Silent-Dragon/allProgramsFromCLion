/* Constructive Algorithms Template
 */

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 1e5; //max n we can have
int n, t;

void swap(int b, int c, int bIndex, int cIndex, int a[]) {
    //HERE WE DO CUSTOM SWAP
    //e.g. only swap numbers if they are a multiple of 2

    /*
    if (b meets condition && c meets condition) {
        a[bIndex] = c;
        a[cIndex] = b;
    }
     */
}

void customSort(string a) {
    //HERE YOU NEED TO SORT THIS ARRAY WITH THE CUSTOM SORT REQUIRED
    //e.g. sort in reverse order
    sort(a.begin(), a.end()); //we only need to sort in alphabetical order

    /* not needed in this case
    for (int i = 0; i < n; i++) {
        swap(a[i], a[i + 1], i, i + 1, a); not needed
    } */
}

int main() {

    cin >> t; //test cases

    for (int testcase = 1; testcase <= t; testcase++) {
        //START OF INPUT
        cin >> n; //length of sequence

        string a; //sequence
        cin >> a; //string so no for loop needed
        //END OF INPUT

        //CUSTOM SORT START
        customSort(a);
        //CUSTOM SORT END

        //OUTPUT START
        cout << a << endl;
        //OUTPUT END
    }

    return 0;
}