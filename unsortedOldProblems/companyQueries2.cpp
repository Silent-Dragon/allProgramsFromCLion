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

long long int n, queries;
int nxt[LOG][N];
vector <int> revGraph[N];
long long int dis[N];
//int prevMoveForEachCoordinate[N]

void DFS(int node) {
    for (auto itr : revGraph[node]) {
        dis[itr] = dis[node] + 1;
        DFS(itr);
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> queries;

    nxt[0][1] = 0;
    for (int i = 2; i <= n; i++) {
        long long int endNode;
        cin >> endNode;

        nxt[0][i] = endNode;
        revGraph[endNode].push_back(i);
    }

    //dis[1] = 0; already 0
    DFS(1);

    //COMPUTATION
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            nxt[k][i] = nxt[k - 1][nxt[k - 1][i]];
        }
    }

    //PROCESS QUERIES AND GET RESULTS FROM COMPUTATION
    for (int q = 1; q <= queries; q++) {
        long long int startNode, endNode, steps;
        cin >> startNode >> endNode;

        //MOVE A & B TO THE SAME LEVEL
        if (dis[startNode] < dis[endNode]) {
            swap(startNode, endNode);
        }
        steps = dis[startNode] - dis[endNode];

        for (int i = 0; i < LOG; i++) {
            if ((steps & (1 << i)) > 0) {
                startNode = nxt[i][startNode];
            }
        }

        if (startNode == endNode) { //startNode was the root
            cout << startNode << endl; //or endNode
        } else {
            //FIND LCA
            for (int i = LOG - 1; i >= 0; i--) {
                if (nxt[i][startNode] != nxt[i][endNode]) {
                    startNode = nxt[i][startNode];
                    endNode = nxt[i][endNode];
                }
            }

            cout << nxt[0][startNode] << endl; //or endNode
        }
    }

    return 0;
}