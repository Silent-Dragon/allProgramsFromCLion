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

int n, m, queries, k, check;
int nxt[LOG][N];
//int prevMoveForEachCoordinate[N]

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> queries;

    nxt[0][1] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> nxt[0][i];
    }

    //COMPUTATION
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            nxt[k][i] = nxt[k - 1][nxt[k - 1][i]];
        }
    }

    //PROCESS QUERIES AND GET RESULTS FROM COMPUTATION
    for (int q = 1; q <= queries; q++) {
        int startNode, steps;
        cin >> startNode >> steps;

        for (int i = 0; i < LOG; i++) {
            if ((steps & (1 << i)) > 0) {
                startNode = nxt[i][startNode];
            }
        }

        if (startNode == 0) {
            cout << -1 << endl;
        } else {
            cout << startNode << endl;
        }
    }
    cout << endl;



    return 0;
}

//THIS IS RECURSSIVE DP