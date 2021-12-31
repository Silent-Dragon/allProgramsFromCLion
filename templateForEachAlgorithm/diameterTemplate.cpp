///longest path inside a graph is diameter

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

long long int n, m, queries, step, ans;
vector <int> graph[N];
long long int dis[N];
long long int maxLength[N];
//int prevMoveForEachCoordinate[N];

void diameter(int node) {
    int max = 0;
    int secondMax = 0;

    //CALCULATE MAXLENGTH VALUES
    for (auto itr : graph[node]) {
        if (dis[itr] > max) {
            secondMax = max;
            max = dis[itr];
        } else if (dis[itr] > secondMax) {
            secondMax = dis[itr];
        }
    }

    //CHECK HOW MANY CHILDREN A NODE HAS TO FIND MAXLENGTH
    if (graph[node].size() == 0) {
        maxLength[node] = 0;
    } else if (graph[node].size() == 1) {
        maxLength[node] = max + 1;
    } else {
        maxLength[node] = max + secondMax + 2;
    }

    if (maxLength[node] > ans) {
        ans = maxLength[node];
    }
}

long long int dfs(int node, int parentNode) {
    if (parentNode != 0) {
        graph[node].erase(find(graph[node].begin(), graph[node].end(), parentNode));
    }

    for (auto itr : graph[node]) {
        dis[node] = max(dis[node], dfs(itr, node) + 1);
    }

    return dis[node];
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

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        diameter(i);
    }

    cout << ans << endl;
    return 0;
}