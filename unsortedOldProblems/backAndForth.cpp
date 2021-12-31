#include <iostream>
#include <vector>

using namespace std;

int possibleAnswers[2000];

void friday(int b1milk, vector<int> B1, vector<int> B2) {
    for (int i = 0; i < B2.size(); i++) {
        int x = B2[i];
        possibleAnswers[b1milk + x] = 1; // record this value as possible
    }
}

void thursday(int b1milk, vector<int> B1, vector<int> B2) {
    for (int i = 0; i < B1.size(); i++) {
        int x = B1[i];
        vector<int> newB2 = B2;
        newB2.push_back(x);

        vector<int> newB1 = B1;
        newB1.erase(newB1.begin() + i);

        friday(b1milk - x, newB1, newB2);
    }
}

void wednesday(int b1milk, vector<int> B1, vector<int> B2) {
    for (int i = 0; i < B2.size(); i++) {
        int x = B2[i];

        vector<int> newB1 = B1;
        newB1.push_back(x);

        vector<int> newB2 = B2;
        newB2.erase(newB2.begin() + i);

        thursday(b1milk + x, newB1, newB2);
    }
}

void tuesday(int b1milk, vector<int> B1, vector<int> B2) {
    for (int i = 0; i < B1.size(); i++) {
        int x = B1[i];
        vector<int> newB2 = B2;
        newB2.push_back(x);

        vector<int> newB1 = B1;
        newB1.erase(newB1.begin() + i);

        wednesday(b1milk - x, newB1, newB2);
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
   // freopen("in.txt", "r", stdin);

    int n;
    int answer = 0;
    vector<int> B1, B2;

    for (int i = 0; i < 10; i++) {
        cin >> n;
        B1.push_back(n);
    }

    for (int i = 0; i < 10; i++) {
        cin >> n;
        B2.push_back(n);
    }

    tuesday(1000, B1, B2);

    for (int i = 0; i < 2000; i++) {
        answer += possibleAnswers[i];
    }

    cout << answer << endl;

    return 0;
}