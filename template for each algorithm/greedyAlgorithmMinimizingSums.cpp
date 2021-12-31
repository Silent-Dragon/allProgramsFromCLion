#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long long int n = 0;
long double ans = 0;
long double median = 0;

vector <int> numbers;

int main() {
    //freopen("in.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m = 0;
        cin >> m;
        numbers.push_back(m);
    }

    sort(numbers.begin(), numbers.end());
    median = numbers[n / 2]; //median for both odd and even cases is n / 2

    for (int i = 0; i < n; i++) {
        ans += abs(median - numbers[i]);
    }

    cout << (long long)ans << endl;

    return 0;
}
