#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int A[100], B[100], G[100];

int correctShell(int startingShell) {
    int currentShell = startingShell;
    int correct = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == currentShell) {
            currentShell = B[i];
        }

        else if (B[i] == currentShell) {
            currentShell = A[i];
        }

        if (currentShell == G[i]) {
            correct++;
        }
    }
    return correct;
}



int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    //freopen("in.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, g;
        cin >> A[i] >> B[i] >> G[i];
    }

    int ans = 0;
    for (int i = 1; i <= 3; i++) {
        ans = max(ans, correctShell(i));
    }

    cout << ans << endl;

   return 0;
}


