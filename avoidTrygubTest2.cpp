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
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 1000;
const int modulo = (int)1e9 + 7;
string originalSequence;
int t, n, occurenceOfT;

int main() {
    //my plan:
    //i am going to put all occurances of the letter 't' at the end of the string i am given
    //this will be swapped with whatever letter was there (as long as it is not a 't')
    //e.g. antontrygub then this will become anbonurygtt since i swapped b->t and u->t

    cin >> t;
    for (int i = 1; i <= t; i++) {
        //innit
        occurenceOfT = 0;
        n = 0;
        originalSequence = ' ';

        //input
        cin >> n;
        cin >> originalSequence;

        //implementation
        for (int j = 0; j < n; j++) {
            //if we find a t
            if (originalSequence[j] == 't') {
                //occurences increases
                occurenceOfT++;

                //swap with n - occurences and current place
                originalSequence[j] = originalSequence[n - occurenceOfT]; //have moved the non 't' letter
                originalSequence[n - occurenceOfT] = 't'; //have moved 't'
            }
        }

        cout << originalSequence << endl;
    }

    return 0;
}