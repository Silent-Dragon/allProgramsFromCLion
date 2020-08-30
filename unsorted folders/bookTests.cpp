#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <iterator>
#include <deque>
#include <algorithm>

using namespace std;

//map <int, int> m;
vector <int> vec;

int main() {

    vec.push_back(3);
    vec.push_back(7);

    vec[1] = 5;
    cout << vec[1] << endl;
    return 0;
    //vector <int>::iterator low;

    //low = lower_bound(v.begin(), v.end(), n + 1); //          ^
    //cout << "lower_bound at position " << (low - v.begin()) << '\n';
}