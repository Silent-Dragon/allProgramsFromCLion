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

long long int n;
vector <int> graph[N];
long long int dis[N];

vector <int> revGraph[N];
long long int revDis[N];
//int prevMoveForEachCoordinate[N];

long long int dfs(int node, int parentNode) {
    if (parentNode != 0) {
        graph[node].erase(find(graph[node].begin(), graph[node].end(), parentNode));
    }

    for (auto itr : graph[node]) {
        dis[node] = max(dis[node], dfs(itr, node) + 1);
    }

    return dis[node];
}

// function to pre-calculate
// which stores the maximum height when traveled
// via parent

void dfs2(int node, int parent) {
    int max1 = -1, max2 = -1;

    for (int itr : revGraph[node]) {
        if (itr == parent) {
            continue;
        }

        if (dis[itr] >= max1) {
            max2 = max1;
            max1 = dis[itr];
        } else if (dis[itr] > max2) {
            max2 = dis[itr];
        }
    }

    for (int itr : revGraph[node]) {
        if (itr == parent) {
            continue;
        }

        long long int longest = max1;

        if (max1 == dis[itr]) {
            longest = max2;
        }

        revDis[itr] = 1 + max(revDis[node], 1 + longest);

        dfs2(itr, node);

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

        revGraph[startNode].push_back(endNode);
        revGraph[endNode].push_back(startNode);

        startNode = 0;
        endNode = 0;
    }

    dfs(1, 0);

    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << max(dis[i], revDis[i]) << " ";
    }
    cout << endl;

    return 0;
}