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
vector <int> graph2[N];
long long int dis[N];
long long int dis2[N];
long long int maxLength[N];
vector <int> list;
//int prevMoveForEachCoordinate[N];

/*
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
*/

long long int dfs(int node, int parentNode) {
    if (parentNode != 0) {
        graph[node].erase(find(graph[node].begin(), graph[node].end(), parentNode));
    }

    for (auto itr : graph[node]) {
        dis[node] = max(dis[node], dfs(itr, node) + 1);
    }

    return dis[node];
}

long long int dfs2(int node, int parentNode) {
    if (parentNode != 0) {
        graph2[node].erase(find(graph2[node].begin(), graph2[node].end(), parentNode));
    }

    for (auto itr : graph2[node]) {
        dis2[node] = max(dis2[node], dfs(itr, node) + 1);
    }

    return dis2[node];
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
        graph2[startNode].push_back(endNode);
        graph2[endNode].push_back(startNode);

        startNode = 0;
        endNode = 0;
    }

    dfs(1, 0);

    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < dis[i]) {
            max = i;
        }
    }

    list.push_back(max);
    dfs2(max, 0);

    int max2 = 0;
    int max2Value = 0;
    for (int i = 1; i <= n; i++) {
        if (max2 < dis[i]) {
            list.clear();
            list.push_back(max);
            list.push_back(max2);

            max2Value = dis[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (list[i] != 0) {
            cout << max2Value + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}