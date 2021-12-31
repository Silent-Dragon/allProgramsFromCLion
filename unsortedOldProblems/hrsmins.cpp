#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

int hrs;
int mins;

void hoursMins (int n) {

    int mins = n % 60;
    n -= mins;
    int hrs = n / 60;

    cout << hrs << " hour " << mins << " mins" << endl;

}


int main() {

  int n = 0;
  cin >> n;

  hoursMins(n);
}

