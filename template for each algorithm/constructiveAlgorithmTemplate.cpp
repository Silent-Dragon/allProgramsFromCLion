/* Constructive Algorithms Template
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5; //max n we can have
int n;

void swap(int b, int c, int bIndex, int cIndex, int a[]) {
    //HERE WE DO CUSTOM SWAP
    //e.g. only swap numbers if they are a multiple of 2

    if (b meets condition && c meets condition) {
        a[bIndex] = c;
        a[cIndex] = b;
    }
}

void customSort(int a[]) {
    //HERE YOU NEED TO SORT THIS ARRAY WITH THE CUSTOM SORT REQUIRED
    //e.g. sort in reverse order

    for (int i = 0; i < n; i++) {
        swap(a[i], a[i + 1], i, i + 1, a);
    }
}

int main() {

    //START OF INPUT
    cin >> n; //length of sequence

    int a[n]; //sequence
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //END OF INPUT

    //CUSTOM SORT START
    customSort(a);
    //CUSTOM SORT END

    //OUTPUT START
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    //OUTPUT END

    return 0;
}