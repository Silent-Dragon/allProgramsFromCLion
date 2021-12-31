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

long long int n, m, queries, step;
int nxt[LOG][N];
int minWeight[LOG][N];
long long int sum[LOG][N];
//int prevMoveForEachCoordinate[N]

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> step;

    //IN
    for (int i = 1; i <= n; i++) {
        cin >> nxt[0][i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> minWeight[0][i];
        sum[0][i] = minWeight[0][i];
    }

    //COMPUTATION
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            nxt[k][i] = nxt[k - 1][nxt[k - 1][i]];

            //min weight in path
            minWeight[k][i] = min(minWeight[k - 1][i], minWeight[k - 1][nxt[k - 1][i]]);
            //minWeight is the min of the prev min weight or what I currently have

            //total sum of weights so far
            sum[k][i] = sum[k - 1][i] + sum[k - 1][nxt[k - 1][i]];
            //sum is the prev total weight + current total weight

        }
    }

    //PROCESS QUERIES AND GET RESULTS FROM COMPUTATION
    for (int q = 1; q <= n; q++) {
        int startNode, minimumWeightForCurrentNode, totalWeight, steps;
        startNode = q;
        steps = step;

        for (int i = 0; i < LOG; i++) {
            if ((steps & (1 << i)) > 0) {
                startNode = nxt[i][startNode];
                minimumWeightForCurrentNode = minWeight[i][startNode];
                totalWeight = sum[i][startNode];
            }
        }

        if (startNode == 0) {
            cout << -1 << endl;
        } else {
            cout << totalWeight << " " << minimumWeightForCurrentNode << endl;
        }
    }

    return 0;
}