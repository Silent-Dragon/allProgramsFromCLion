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

long long int n = 0; //concert tickets available
long long int m = 0; //number of people
long long int k = 0;

multiset <int> ticketPrices;

long long int get_int() {
    char x = getchar();
    while (!isdigit(x)) x = getchar();
    long long int res = 0;
    while (isdigit(x)) res = res * 10 + x - '0', x = getchar();
    return res;
}

int main() {
    n = get_int();
    m = get_int();

    for (int i = 0; i < n; i++) {
        k = 0;
        k = get_int();

        ticketPrices.insert(k);
    }

    int maximumPrices[m];
    for (int i = 0; i < m; i++) {
        maximumPrices[i] = get_int();
    }

    //for each person's max price, we need to match their price with a valid ticket
    for (int i = 0; i < m; i++) {
        if (ticketPrices.size() == 0) {
            cout << "-1 ";
            continue; //if we have no more tickets, we won't be able to match new people
        }

        multiset<int>::iterator upperBoundPointer;
        //upperBoundPointer = upper_bound(ticketPrices.begin(), ticketPrices.end(), maximumPrices[i]); //here we are looking for the best ticket price
        upperBoundPointer = ticketPrices.upper_bound(maximumPrices[i]); //same as above


        if (upperBoundPointer != ticketPrices.begin()) { //as long as we can access the position before
            upperBoundPointer--;

            cout << *upperBoundPointer << " ";
            ticketPrices.erase(upperBoundPointer);

        } else {
            cout << "-1 ";
        }

    }




    return 0;
}
