#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <queue>

using namespace std;

const int N = (int)1e5 + 1;

int n, m;
int currentNode;
set <pair <long long int, int>> setShortestDistance;
long long int arrayShortestDistance[N];
vector <pair <int, int>> graph[N];

void dijakstra() {
    while (!setShortestDistance.empty()) {
        currentNode = setShortestDistance.begin()->second;

        for (auto itr : graph[currentNode]) {
            if (arrayShortestDistance[currentNode] + itr.second < arrayShortestDistance[itr.first]) {
                setShortestDistance.erase({arrayShortestDistance[itr.first], itr.first});
                arrayShortestDistance[itr.first] = arrayShortestDistance[currentNode] + itr.second;
                setShortestDistance.insert({arrayShortestDistance[itr.first], itr.first});
            }
        }

        setShortestDistance.erase(setShortestDistance.begin());
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int startNode;
        int endNode;
        int length;

        cin >> startNode >> endNode >> length;

        graph[startNode].push_back({endNode, length});

        startNode = 0;
        endNode = 0;
        length = 0;
    }

    for (int i = 1; i <= n; i++) {
        arrayShortestDistance[i] = 1e18;
    }
    arrayShortestDistance[1] = 0;
    setShortestDistance.insert({0, 1});

    dijakstra();

    for (int i = 1; i <= n; i++) {
        cout << arrayShortestDistance[i] << " ";
    }
    cout << endl;

    return 0;
}
