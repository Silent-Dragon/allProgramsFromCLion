#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

const int MAX_N = 100;

int A[MAX_N + 1];
int order[MAX_N + 1];
int originalOrder[MAX_N + 1];

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        cin >> order[i];

    for (int a = 0; a < 3; a++) {
        for (int i = 1; i <= n; i++) {
            originalOrder[i] = order[A[i]];
        }
        for (int i = 1; i <= n; i++) {
            order[i] = originalOrder[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << order[i] << endl;
    }

    return 0;
}