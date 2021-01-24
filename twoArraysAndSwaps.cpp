#include <iostream>
#include <set>

using namespace std;

long long int n, k, testCases;
set <int> setA;
set <int> setB;

int main() {

    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        cin >> n >> k;

        int a[n];
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            setA.insert(a[j]);
        }

        int b[n];
        for (int j = 0; j < n; j++) {
            cin >> b[j];
            setB.insert(b[j]);
        }

        for (int j = 0; j < k; j++) {
            int setAstart = 0;
            int setbEnd = 0;

            if (*setA.begin() < *setB.rbegin()) {
                setAstart = *setA.begin();
                setbEnd = *setB.rbegin();

                //remove the start of setA and end of setB
                setA.erase(setA.begin());
                setB.erase(--setB.end());

                //then we need to insert each of these into the other set
                setA.insert(setbEnd);
                setB.insert(setAstart);
            } else {
                break; //no point in swapping
            }
        }

        int sum = 0;
        for (auto itr : setA) {
            sum += itr;
        }
        cout << sum << endl;

        setA.clear();
        setB.clear();
    }
}