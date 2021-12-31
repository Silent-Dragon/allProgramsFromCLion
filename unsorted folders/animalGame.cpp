#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <string> characteristics[100];

int numCommon(int i, int j) {
    int count = 0;

    vector<string> v1 = characteristics[i];
    vector<string> v2 = characteristics[j];

    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i] == v2[j]) {
                count++;
            }
        }
    }


    return count;
}

int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    //freopen("in.txt", "r", stdin);

    cin >> n;
    string s;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> s >> k;
        for (int j=0; j<k; j++) {
            cin >> s;
            characteristics[i].push_back(s);
        }
    }

    int largest = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            largest = max(largest, numCommon(i, j));
        }
    }
    //we put +1 because we need a bonus question which is the final question 'Is the animal BLA', to which we will get another 'yes'
    cout << largest + 1 << endl;
    return 0;
}