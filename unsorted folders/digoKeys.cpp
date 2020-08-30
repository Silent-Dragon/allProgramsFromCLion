#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define pb push_back

const int N = 507;

int t, n, M, k;
vector <int> keys[N];

bool visited[N];
// visited[v] = 1
void bfs(int v) {
    visited[v] = 1;
    for (auto to : g[v]) {
        if (!visited[to]) dfs(to);
    }
    /*
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!visited[to]) dfs(to);
    }*/
}

int main() {
    //Here I get my input from file in.text
    freopen ("in.txt", "r", stdin);
    //Here I get the value of t, which is the number of test cases
    //cout << "Enter t: ";
    cin >> t;
    //cout << endl;

    for (int a = 0; a < t; a++) {
        cin >> n; //number of locks/boxes
        for (int i = 1; i <= n - 1; i++) {
            cin >> M; //number of keys
            boxAndNoKeys.insert(pair<int, int>(i, M));
            for (int j = 0; j < M; j++) {
                cin >> k;//which box the jth key can open
                keys[k].push_back(i);
                keys[i].push_back(k);

                // g[i].pb(k);
                // g[k].pb(i);
            }
        }
        bfs(0);//call our function with the current info
        keys.clear();//clear our vector for the next test case
    }


/*
    cout << "T: " << t;
    cout << endl;

    cout << "N: " << n;
    cout << endl;

    cout << "M:" << M;
    cout << endl;

    cout << "K:" << k;
    cout << endl;

    for (unsigned int i = 0; i < keys.size(); i++) {
        cout << keys[i] << " ";
    }
*/ // Info checked -- all good

    return 0;
}