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

long long int n = 0;
long long int timeTaken = 0;
long long int currentTime1 = 0;
long long int currentTime2 = 0;
long long int lengthOflastBookRead1 = 0;
long long int lengthOflastBookRead2 = 0;
multiset <int> booksLeftToRead1;
multiset <int> booksLeftToRead2;
multiset <int>::iterator bookToRemove1;
multiset <int>::iterator bookToRemove2;


int reading2() {
    while (booksLeftToRead1.size() != 0 && booksLeftToRead2.size() != 0) {
        if (currentTime2 > currentTime1) {
            timeTaken += currentTime1 - currentTime2;
            return 0;
        } else if (booksLeftToRead2.size() == 1 && *booksLeftToRead2.begin() == lengthOflastBookRead1) {
            timeTaken += currentTime2;
            return 0;
        }

        if (*booksLeftToRead2.rbegin() != lengthOflastBookRead1) {
            currentTime2 += *booksLeftToRead2.rbegin();
            lengthOflastBookRead2 = *booksLeftToRead2.rbegin();

            bookToRemove2 = booksLeftToRead2.end();
            bookToRemove2--;

            booksLeftToRead2.erase(bookToRemove2);
        } else {
            if (booksLeftToRead2.size() >= 2) {
                currentTime2 += *booksLeftToRead2.rbegin()--;
                lengthOflastBookRead2 = *booksLeftToRead2.rbegin()--;

                bookToRemove2 = booksLeftToRead2.end();
                bookToRemove2--;
                bookToRemove2--;

                booksLeftToRead2.erase(bookToRemove2);
            }
        }

        timeTaken += currentTime2;
    }

    return 0;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int k = 0;
        cin >> k;

        booksLeftToRead1.insert(k);
        booksLeftToRead2.insert(k);
    }


    while (booksLeftToRead1.size() != 0 && booksLeftToRead2.size() != 0) {
        if (currentTime1 > currentTime2) {
            timeTaken += currentTime2 - currentTime1;
            reading2();
        } else if (booksLeftToRead1.size() == 1 && *booksLeftToRead1.begin() == lengthOflastBookRead2) {
            reading2();
        }

        if (*booksLeftToRead1.rbegin() != lengthOflastBookRead2) {
            currentTime1 += *booksLeftToRead1.rbegin();
            lengthOflastBookRead1 = *booksLeftToRead1.rbegin();

            bookToRemove1 = booksLeftToRead1.end();
            bookToRemove1--;

            booksLeftToRead1.erase(bookToRemove1);
        } else {
            if (booksLeftToRead1.size() >= 2) {
                currentTime1 += *booksLeftToRead1.rbegin()--;
                lengthOflastBookRead1 = *booksLeftToRead1.rbegin()--;

                bookToRemove1 = booksLeftToRead1.end();
                bookToRemove1--;
                bookToRemove1--;

                booksLeftToRead1.erase(bookToRemove1);
            }
        }

        timeTaken += currentTime1;

    }

    cout << timeTaken << endl;

    return 0;
}