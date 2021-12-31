#include <iostream>
#include <vector>

using namespace std;

vector <int> mySet;
vector <int> permutation;
int chosen[1000];
int n, value;

void search() {
    if (permutation.size() == n) {
        // a full permutation has now been generated
        for (auto itr : permutation) {
            cout << itr << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) {
                continue;
            }
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << "Enter n." << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter mySet[" << i << "]." << endl;
        cin >> value;
        mySet.push_back(value);
    }

    cout << "Going to generate permutations." << endl;
    search();

    return 0;
}