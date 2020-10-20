#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = (int)2e5 + 7;

long long int n;
long long int sizeOfSubtree[N];

vector <int> graph[N];
long long int maxDisToDescendants[N];
long long int sumDisToDescendants[N];

long long int maxDisToAncestors[N];
long long int sumDisToAncestors[N];

long long int dfs(int node, int parentNode) {
    if (parentNode != 0) {
        graph[node].erase(find(graph[node].begin(), graph[node].end(), parentNode));
    }

    for (auto itr : graph[node]) {
        sumDisToDescendants[node] += dfs(itr, node);
        sumDisToDescendants[node] += sizeOfSubtree[itr];
        //down[node] = down[child1] + sizeofsubtree[child1] + down[child2] + sizeofsubtree[child2].. etc.

        sizeOfSubtree[node] += sizeOfSubtree[itr];
    }

    return sumDisToDescendants[node];
}

void dfs2(int node) {
    for (int itr : graph[node]) {
        sumDisToAncestors[itr] = (sumDisToDescendants[node] - (sumDisToDescendants[itr] + sizeOfSubtree[itr])) + sumDisToAncestors[node] + (n - sizeOfSubtree[itr]);
        //up[child] = (down[node] - (down[child] + sizeofsubtree[child)) + up[node] + (no of nodes - sizeofsubtree[child])
        dfs2(itr);
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    //IN
    for (int i = 1; i <= n - 1; i++) {
        sizeOfSubtree[i] = 1;
        //n - 1 nodes are set

        int startNode;
        int endNode;

        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);
        graph[endNode].push_back(startNode);

        startNode = 0;
        endNode = 0;
    }
    sizeOfSubtree[n] = 1;
    //all n nodes are set

    dfs(1, 0);
    dfs2(1);

    for (int i = 1; i <= n; i++) {
        cout << sumDisToAncestors[i] + sumDisToDescendants[i] << " ";
    }
    cout << endl;

    return 0;
}