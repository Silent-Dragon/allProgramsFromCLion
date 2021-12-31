#include <iostream>
#include <vector>

using namespace std;

vector <int> mySet;
vector <int> subset;
int n, value;

void search(int k) {
    if (k == n) {
        // a full subset has now been generated
        if (subset.size() == 0) {
            cout << "Empty subset." << endl;
        } else {
            for (auto itr : subset) {
                cout << itr << " ";
            }
            cout << endl;
        }
    } else {
        search(k + 1);
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
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

    cout << "Going to generate subsets." << endl;
    search(0);

    return 0;
}