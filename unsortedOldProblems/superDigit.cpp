#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int superDigit( long long k ) {
    if (k < 10) {
        return k;
    }

    long long sum = 0;

    while(k > 0) {
        sum += k % 10;
        k = k / 10;
    }

    return superDigit(sum);
}


long long initialSum(string number) {
    long long sum = 0;

    for (int i = 0; i < number.size(); i++) {
        sum += number[i] - '0';
    }

    return sum;
}


int main() {
    string n;
    cout << "Input n: ";
    cin >> n;
    cout << endl;

    int k;
    cout << "Input k: ";
    cin >> k;
    cout << endl;

    long long repeated = initialSum(n) * k;

    long long result = superDigit(repeated);

    cout << result << endl;




    return 0;
}