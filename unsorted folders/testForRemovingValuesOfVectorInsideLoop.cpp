#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = (int)2e5 + 7;
//const int K = (int)1e9 + 7;
const int LOG = 30; //of K
const int modulo = (int)1e9 + 7;

int n;
vector <int> testing;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int input = 0;
        cin >> input;

        testing.push_back(input);
    }

    for (auto itr : testing) {
        cout << itr << " ";

        if (itr % 2 == 0) {
            cout << "Multiple " << itr << endl;
            testing.erase(find(testing.begin(), testing.end(), itr));
        }
    }
    cout << endl;

    return 0;
}