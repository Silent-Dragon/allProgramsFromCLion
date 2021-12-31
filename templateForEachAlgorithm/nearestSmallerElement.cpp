/* Nearest Smaller Element Template
 */

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 1e5; //max n we can have
const int iInfinity = 1e9 + 5;
const long long int lliInfinity = (long long)1e18 + 5;

int n;
int a[N];
stack <int> s;
vector <int> ans;

void nearestSmallerElement() {
    ans.push_back(-1);

    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            ans.push_back(-1);
            s.push(a[i]);
        } else if (s.top() < a[i]) {
            ans.push_back(s.top());
            s.push(a[i]);
        } else {
            while (!s.empty() && s.top() >= a[i]) {
                s.pop();
            }

            if (s.empty()) {
                ans.push_back(-1);
                s.push(a[i]);
            } else {
                ans.push_back(s.top());
                s.push(a[i]);
            }
        }
    }
}

int main() {

    //INIT START
    //INIT END

    //INPUT START
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //INPUT END


    //NEAREST SMALLER ELEMENT START
    nearestSmallerElement();
    //NEAREST SMALLER ELEMENT END

    /*
     * APPLY SPECIFIC METHOD
     * Now that we have applied Nearest Smaller Element, we can apply specific
     * methods/calculations to the problem
     * */

    //PRINT SOLUTION START
    for (auto itr : ans) {
        cout << itr << " ";
    }
    cout << endl;
    //PRINT SOLUTION END

    return 0;
}