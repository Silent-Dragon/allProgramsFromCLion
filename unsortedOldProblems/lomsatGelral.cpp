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
map <int, int> occurancesForEachColour[N]; //colour, occurances
map <int, int> sumOfOccurances[N]; //occurances, sum of occurances

int n;
int sumOfDominantColours[N];
int colour[N];
vector <int> graph[N];

void merge(map <int, int> &map1, map <int, int> &map2) { //input will always make it so that map 1 needs to be merged to map 2
    int sizeOfMap1 = map1.size();
    int sizeOfMap2 = map2.size();

    if (sizeOfMap1 < sizeOfMap2) { //do what input asked
        for (auto itr : map1) { //go through values of map 1
            map2.insert(itr); //here we're adding values from map 1 and inserting them to map 2
        }
    } else { //do other way around than what input asked and then swap
        for (auto itr : map2) { //go through values of map 2
            map1.insert(itr); //here we're adding values from map 2 and inserting them to map 1
        }

        swap(map1, map2); //this is not slow because the values are not swapped, the references are swapped (names)
    }

    map1.clear(); //here we clear map 1 since all it's values have been copied to map 2 and it's no longer needed
}

void dfs(int currentNode, int parentNode) {
    for (auto child : graph[currentNode]) {
        if (child == parentNode) {
            continue;
        }

        dfs(child, currentNode);

        merge(occurancesForEachColour[child], occurancesForEachColour[currentNode]);



    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> colour[i];

        occurancesForEachColour[i][colour[i]] = 1;
    }

    for (int i = 1; i <= n - 1; i++) {
        int startNode, endNode;
        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);
        graph[endNode].push_back(startNode);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << sumOfDominantColours[i] << " ";
    }
    cout << endl;
}