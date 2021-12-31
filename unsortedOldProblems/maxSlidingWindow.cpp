#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <iterator>

using namespace std;

long long int n, k;
vector <int> out;

vector<int> maxSlidingWindow(vector<int>& arr, int k)  {
    int l = arr.size();
    deque <int> dq;

    if (arr.size() == 0)
        return out;
    if (arr.size() == 1 || k == 1) {
        return arr;
    }

    for (int i = 0; i < k; i++) {
        if (dq.empty()) {
            dq.push_back(i);
        }

        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i = k; i < arr.size(); i++) {
        out.push_back(arr[dq.front()]);

        int currentElement = arr[i];

        while (!dq.empty() && arr[dq.back()] < currentElement) {
            dq.pop_back();
        }

        while (!dq.empty() && dq.front() + k <= i) {
            dq.pop_front();
        }

        dq.push_back(i);
    }

    out.push_back(arr[dq.front()]);
    return out;
}

int main() {

    ///INPUT
    cin >> n >> k;
    vector <int> input;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;

        input.push_back(j);
    }

    maxSlidingWindow(input, k);

    for (auto itr : out) {
        cout << itr << endl;
    }

    return 0;
}
