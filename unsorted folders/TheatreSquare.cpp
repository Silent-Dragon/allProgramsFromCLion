#include <iostream>
#include <cmath>

using namespace std;
int main() {

    long long int n;
    long long int m;
    long long int a;
    int count = 0;
    long long int numberOfFlagstones;

    cin >> m; //width
    cin >> n; //length
    cin >> a; //sideOfFlagstone


    long long int areaOfFlagstone = a * a;
/*
    while (n % a != 0) {
        n ++;
    }

    while (m % a != 0) {
        m ++;
    }
*/
    n = ceil(n / (double)a);
    m = ceil(m / (double)a);

   // cout << n << " " << m;
  //  cout << endl;
    numberOfFlagstones = n * m;

    cout << numberOfFlagstones;
/*
    while (remainingAreaOfSquare > 0) {
        remainingAreaOfSquare = remainingAreaOfSquare - areaOfFlagstone;
        count++;
    }
*/


  //  count = areaOfSquare / areaOfFlagstone;

   // cout << count;



}