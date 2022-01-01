#include <iostream>
#include <map>
#include <set>

using namespace std;

int n = 0; //size of our sequence
int k = 0; //size of sliding window
long long int ans = 0;
long long int sum1 = 0;
long long int sum2 = 0;
double median = 0;

multiset <int> firstHalf;
multiset <int> secondHalf;
multiset <int>::iterator pointer1;
multiset <int>::iterator pointer2;


void balance_multisets() {
    while (secondHalf.size() > 0 && firstHalf.size() > 0 && *firstHalf.rbegin() > *secondHalf.begin()) {
        if (firstHalf.size() >= secondHalf.size()) {
            sum2 += *firstHalf.rbegin();
            secondHalf.insert(*firstHalf.rbegin());

            sum1 -= *--firstHalf.end();
            firstHalf.erase(--firstHalf.end());
        } else {
            sum1 += *secondHalf.begin();
            firstHalf.insert(*secondHalf.begin());

            sum2 -= *secondHalf.begin();
            secondHalf.erase(secondHalf.begin());
        }
    }
    while (firstHalf.size() < secondHalf.size()) {
        sum1 += *secondHalf.begin();
        firstHalf.insert(*secondHalf.begin());

        sum2 -= *secondHalf.begin();
        secondHalf.erase(secondHalf.begin());
    }

}

void insert(int x) {
    sum2 += x;
    secondHalf.insert(x);
    balance_multisets();
}

void erase(int x) {
    if (firstHalf.find(x) != firstHalf.end()) {
        sum1 -= x;
        firstHalf.erase(firstHalf.find(x));
    }
    else {
        sum2 -= x;
        secondHalf.erase(secondHalf.find(x));
    }
    balance_multisets();
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < k) {
            insert(a[i]);
        }

    }

    for (int i = 0; i < n - k + 1; i++) {
        //Here we can do whatever action we want with our multisets. This is used to find the median

        ans += *firstHalf.rbegin() * firstHalf.size() - sum1;
        ans += sum2 - *firstHalf.rbegin() * secondHalf.size();

        cout << ans << " ";

        ans = 0;
        erase(a[i]);
        insert(a[i + k]);


        //Here we find min cost:
        cout << *firstHalf.rbegin() << " ";
        erase(a[i]);
        insert(a[i + k]);
    }
    //cout << endl;


    return 0;
}