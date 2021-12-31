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
vector <int> list;
int permanentMark[N];
int tempMark[N];
vector <int> graph[N];

void dfs (int node) {
    //cout << "At node " << node << endl;

    if (permanentMark[node] == 1) {
        //cout << "Already finished this node " << node << endl;
        return;
    }

    if (tempMark[node] == 1) {
        //cycle, not possible to sort topologically
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }

    tempMark[node] = 1;

    for (auto itr : graph[node]) {
        dfs(itr);
    }

    tempMark[node] = 0;
    permanentMark[node] = 1;
    list.push_back(node);
   // cout << "Finished node " << node << endl;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int startNode;
        int endNode;

        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);

        startNode = 0;
        endNode = 0;
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    reverse(list.begin(), list.end());
    for (auto itr : list) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}
