#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int solve = 0;
int n;
int value = 1001;
int temp;
int time[999];

int main() {
    cin >> n;
    int min[n];
    int max[n];

    for (int i = 0; i < n; i++) {
        cin >> min[i] >> max[i];
        for (int j = min[i]; j < max[i]; j++) {
            time[j] += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        temp = 0;
        for (int j = min[i]; j < max[i]; j++) {
            if (time[j] == 1) {
                temp += 1;
            }
        }
        if (temp < value) {
            value = temp;
        }
    }
    solve = solve - value;
    cout << solve;

}