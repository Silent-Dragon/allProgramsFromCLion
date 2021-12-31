#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main() {
    ///init
    unordered_map <int, int> myUnorderedMap;

    ///insertion
    myUnorderedMap[0] = 63;
    myUnorderedMap[1] = 5;
    myUnorderedMap[2] = 97;
    myUnorderedMap[3] = 22;
    myUnorderedMap[4] = 1;

    ///iterating and printing
    for (auto itr = myUnorderedMap.begin(); itr != myUnorderedMap.end(); itr++) {
        cout << itr-> first << " " << itr->second << endl;
    }

    ///start and end
    cout << myUnorderedMap.begin()->second << endl;

    ///trying to print the end with --map.end() but got seg 11

    ///min and max
    cout << max_element(myUnorderedMap.begin(), myUnorderedMap.end())->first << " ";
    cout << min_element(myUnorderedMap.begin(), myUnorderedMap.end())->first << endl;

    ///find by key
    int wantedKey = 3;
    cout << myUnorderedMap.find(wantedKey)->second << endl;

    ///deletion
    myUnorderedMap.erase(wantedKey);
  //  myUnorderedMap.erase(prev(myUnorderedMap.end()));
    myUnorderedMap.erase(myUnorderedMap.begin());

    ///prev did not work (error) but it compiled with seg 11 on Zhan's compiler

    ///clear
    myUnorderedMap.clear();

    return 0;
}
