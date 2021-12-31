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
set <int> setForEachNode[N];

int n;
int distinctColours[N];
int colour[N];
vector <int> graph[N];

void merge(set <int> &set1, set <int> &set2) { //input will always make it so that set 1 needs to be merged to set 2
    int sizeOfSet1 = set1.size();
    int sizeOfSet2 = set2.size();

    if (sizeOfSet1 < sizeOfSet2) { //do what input asked
        for (auto itr : set1) { //go through values of set 1
            set2.insert(itr); //here we're adding values from set 1 and inserting them to set 2
        }
    } else { //do other way around than what input asked and then swap
        for (auto itr : set2) { //go through values of set 2
            set1.insert(itr); //here we're adding values from set 2 and inserting them to set 1
        }

        swap(set1, set2); //this is not slow because the values are not swapped, the references are swapped (names)
    }

    set1.clear(); //here we clear set 1 since all it's values have been copied to set 2 and it's no longer needed
}

void dfs(int currentNode, int parentNode) {
    for (auto child : graph[currentNode]) {
        if (child == parentNode) {
            continue;
        }

        dfs(child, currentNode);
        merge(setForEachNode[child], setForEachNode[currentNode]);
    }

    distinctColours[currentNode] = setForEachNode[currentNode].size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> colour[i];

        setForEachNode[i].insert(colour[i]);
        distinctColours[i] = 1;
    }

    for (int i = 1; i <= n - 1; i++) {
        int startNode, endNode;
        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);
        graph[endNode].push_back(startNode);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << distinctColours[i] << " ";
    }
    cout << endl;
}