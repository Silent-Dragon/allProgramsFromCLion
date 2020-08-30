#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string p = " ";
int l = 0;
int cnt = 0;
vector <int> annex;

void checkCombos(int a[], int i) {

    if (i == l) {
        for (int j = 0; j < annex.size(); j++) {
            cout << annex[j] << " ";
        }
        cout << endl << cnt << endl;
        return;
    }


    if (i == l) {
        for (int j = 0; j < annex.size(); j++) {
            cout << annex[j] << " ";
        }
        cout << endl;
        return;
    }

    bool flag = true;
    for (int j = 0; j < annex.size(); j++) {
        if (a[i] == annex[j]) {
            flag = false;
        }
    }

    if (i >= 2) {
           if (annex[i - 2] < annex[i - 1] || annex[i - 1] < annex[i]) {
               flag = false;
           }
    }

    if (flag) {
        cnt++;
        annex.push_back(i);
    }

    checkCombos(a, i + 1);
}

void bcCheck(int a[]) {
    for (int i = 0; i < p.length(); i++) {
        a[i] = p[i] - 'A' + 1;
    }

    for (int i = 0; i < p.length(); i++) {
        annex.push_back(a[i]);
    }

    checkCombos(a, 0);

    cout << cnt << endl;
}



int main() {
    cin >> l >> p;

    int a[p.length()];
    memset(a, 0, sizeof(a));

    if (l == 1) {
        cout << "1";
    } else if (l == 0) {
        cout << "0";
    } else {
        bcCheck(a);
    }

    return 0;
}