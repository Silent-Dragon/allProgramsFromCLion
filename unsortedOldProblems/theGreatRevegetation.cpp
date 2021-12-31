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

const int MAXN = (int)1e5 + 7;

long long int n, m, newGroup, connectedComponents;
vector <long long int> graph[MAXN];
long long int visited[MAXN];
long long int groups[MAXN];
pair<int, int> same[MAXN];
pair<int, int> different[MAXN];

void convertDecimalToBinary(int n) {

}

void dfs(int node, int group) {
    //cout << "At node " << node << " with group " << group << endl;
    visited[node] = 1;

    for (auto to : graph[node]) {
        if (visited[to] == 0) {
            if (group == 1) {
                newGroup = 2;
            } else {
                newGroup = 1;
            }

            // cout << "Going to node " << to << endl;
            groups[to] = newGroup;
            // cout << "Array 'groups' has " << groups[to] << " in place "<< to << endl;
            dfs(to, newGroup);
        } else {
            //IMPOSSIBLE
            if (groups[to] == group) {
                cout << "0" << endl;
                exit(0);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        char indicator;
        cin >> indicator;

        if (indicator == 'S') {
            int inputField1;
            int inputField2;
            cin >> inputField1 >> inputField2;
            same[i] = {inputField1, inputField2};
        }

        if (indicator == 'D') {
            int inputField1;
            int inputField2;
            cin >> inputField1 >> inputField2;
            different[i] = {inputField1, inputField2};
        }
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            //dfs(i, 1);
            connectedComponents++;
        }
    }




    return 0;
}