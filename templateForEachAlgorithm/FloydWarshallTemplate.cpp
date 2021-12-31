/* Floyd Warshall Template
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int N = 1e3; //max n we can have
const int infinity = 1e8;

int n, m;

int matrix[N][N];
int dist[N][N];
int adj[N][N];

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < infinity && dist[k][j] < infinity) {
                    //min(dist[i][j], dist[i][k] + dist[k][j]);
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << dist[0][0];
}

int main() {

    //INPUT START
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            dist[i][j] = matrix[i][j];
        }
    }
    //INPUT END


    //FLOYD WARSHALL END
    floydWarshall();
    //FLOYD WARSHALL END


     /* APPLY SPECIFIC METHOD
     * Now that we have applied Floyd Warshall, we can apply specific methods/calculations to the
     * problem, e.g. they want the answer for a specific pair of nodes
     */

    //PRINT SOLUTION START
    //PRINT SOLUTION END

    return 0;
}
