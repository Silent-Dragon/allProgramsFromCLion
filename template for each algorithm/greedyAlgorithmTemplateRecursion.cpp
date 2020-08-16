#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

long long int n, steps, currentNumber, answer;

long long int greedyAlgorithm(int number) {
    currentNumber = 0;
    answer = 0;

    while (number) {
        //do some action here, below is an example

        n -= max(0, 1);
        answer++;
    }

    return answer;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    //if you want to go forwards, change to n <= limit
    while (n >= 0) {
        //if you want to go forwards, change to n == limit
        if (n == 0) {
            cout << steps << endl;
            break;
        }

        //if you want to go forwards, change to n += greedyAlgorithm(n);
        n -= greedyAlgorithm(n);
        steps++;
    }

    return 0;
}