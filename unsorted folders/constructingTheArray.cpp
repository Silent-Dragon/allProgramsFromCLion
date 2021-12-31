/* Constructive Algorithms Template
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 2e5 + 7; //max n we can have
long long int n, cnt, t;
long long int a[N]; //alr has 0s
map <pair <int, int>, int> subsequences; //range, start, range

void swap(int b, int c, int bIndex, int cIndex, int a[]) {
    //HERE WE DO CUSTOM SWAP
    //e.g. only swap numbers if they are a multiple of 2
/*
    if (b meets condition && c meets condition) {
        a[bIndex] = c;
        a[cIndex] = b;
    }*/
}

void customSort() {
    //HERE YOU NEED TO SORT THIS ARRAY WITH THE CUSTOM SORT REQUIRED
    //e.g. sort in reverse order
    cnt++;

    //range, start
    pair <int, int> currentRange = (*subsequences.rbegin()).first;

    int currentPos = (-(currentRange.second) + (-(currentRange.second) + currentRange.first - 1)) / 2;
    a[currentPos] = cnt;

    subsequences.erase(--subsequences.end());
    //currentPos = 2 if it starts w/2 then we need to move it to start with 3 length++. if it
    //ends with 2 then we make it end with 1 and length--


    int currentLeft = -(currentRange.second);
    int middle = currentPos;
    int range = currentRange.first;

    if (currentLeft < middle) {
        subsequences[{middle - currentLeft, -currentLeft}] = middle - currentLeft;
        subsequences[{range/2, -(middle + 1)}] = range/2;
    } else if (range <= 1) {
        //nothing
    } else {
        subsequences[{range/2, -(middle + 1)}] = range/2;
    }

    if (cnt < n) {
        customSort();
    }
}

int main() {
    cin >> t;

    for (int test = 1; test <= t; test++) {
        //START OF INPUT
        cin >> n; //length of sequence
        //END OF INPUT

        subsequences[{n, 0}] = n;

        //CUSTOM SORT START
        customSort();
        //CUSTOM SORT END

        //OUTPUT START
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        //OUTPUT END

        cnt = 0;
        subsequences.clear();
    }

    return 0;
}