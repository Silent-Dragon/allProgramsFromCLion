#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int power(int number, int index){

    int result = 1;

    for (int i = 0; i < index; i++){
        result *= number;
    }

    return result;
}

int checkRecursive(int number, int index, int prev = 0, int tempSum = 0){
    int i = prev + 1;
    int results = 0;
    int k = power(i, index);
    while (k + tempSum < number) {
        results += checkRecursive(number, index, i, k+tempSum);
        i++;
        k = power(i, index);
    }

    if (k + tempSum == number) {
        results++;
    }

    return results;
}

int main() {

    int x, n;

    cin >> n >> x;

    cout << checkRecursive(n, x);
    return 0;
}


