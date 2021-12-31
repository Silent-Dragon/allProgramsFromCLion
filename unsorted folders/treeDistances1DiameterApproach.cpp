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

long long int n, distanceToA, distanceToB, A, B;
vector <int> graph[N];
long long int disFromA[N];
long long int disFromB[N];
//int prevMoveForEachCoordinate[N];

void findA(int node, int parentNode, int distance) {
    for (auto itr : graph[node]) {
        if (itr != parentNode) {
            findA(itr, node, distance + 1);
        }
    }

    if (distance > distanceToA) {
        distanceToA = distance;
        A = node;
    }
}

void findBandDisFromA(int node, int parentNode, int distance) {
    for (auto itr : graph[node]) {
        if (itr != parentNode) {
            disFromA[itr] = disFromA[node] + 1;
            findBandDisFromA(itr, node, distance + 1);
        }
    }

    if (distance > distanceToB) {
        distanceToB = distance;
        B = node;
    }
}

void calcDisFromB(int node, int parentNode, int distance) {
    for (auto itr : graph[node]) {
        if (itr != parentNode) {
            disFromB[itr] = disFromB[node] + 1;
            calcDisFromB(itr, node, distance + 1);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    //IN
    for (int i = 1; i <= n - 1; i++) {
        int startNode;
        int endNode;

        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);
        graph[endNode].push_back(startNode);

        startNode = 0;
        endNode = 0;
    }

    //dfs(1, 0);

    findA(1, 0, 0);
    findBandDisFromA(A, 0, 0);
    calcDisFromB(B, 0, 0);

    for (int i = 1; i <= n; i++) {
        cout << max(disFromA[i], disFromB[i]) << " ";
    }   
    return 0;
}