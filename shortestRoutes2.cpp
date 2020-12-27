/* Floyd Warshall Template
 */

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 1000; //max n we can have
const int iInfinity = 1e9 + 5;
const long long int lliInfinity = (long long)1e18 + 5;

int n, m, q;

long long int dist[N][N];

void floydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < lliInfinity && dist[k][j] < lliInfinity) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {

    //INIT START
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            dist[i][j] = lliInfinity;
        }
        dist[i][i] = 0;
    }
    //INIT END

    //INPUT START
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int startNode, endNode, length;
        cin >> startNode >> endNode >> length;

        if (dist[startNode][endNode] > length) {
            dist[startNode][endNode] = length;
            dist[endNode][startNode] = length;
        }
    }
    //INPUT END


    //FLOYD WARSHALL END
    floydWarshall();
    //FLOYD WARSHALL END

    /*
     * APPLY SPECIFIC METHOD
     * Now that we have applied Floyd Warshall, we can apply specific methods/calculations to the
     * problem, e.g. they want the answer for a specific pair of nodes
     * */

    //PRINT SOLUTION START
    for (int testCase = 1; testCase <= q; testCase++) {
        int start, end;
        cin >> start >> end;

        if (dist[start][end] == lliInfinity) {
            cout << -1 << endl;
        } else {
            cout << dist[start][end] << endl;
        }
    }
    //PRINT SOLUTION END

    //cout << lliInfinity << endl;
    return 0;
}