/*A bipartite graph is possible if
 * the graph coloring is possible using two colors
 * such that vertices in a set are colored with the same colo
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5; //max n we can have

int n, m;
int connectedComponents;
int visited[N];
int group[N];
int ans = 1; //possible

vector <int> graph[N];


void findIfGraphIsBipartite(int currentNode, int currentGroup) {
    visited[currentNode] = 1;

    for (auto to : graph[currentNode]) {
        if (!visited[to]) {
            if (group[to] != group[currentGroup]) {
                if (group == 1) {
                    findIfGraphIsBipartite(to, 2);
                } else {
                    findIfGraphIsBipartite(to, 1);
                }
            } else {
                ans = 0; //impossible
            }
        }
    }
}

int main() {

    //INPUT START
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int startNode = 0;
        int endNode = 0;

        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);
        graph[endNode].push_back(startNode);
    }
    //INPUT END


    //FIND IF GRAPH IS BIPARTITE START
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            group[i] = 1;
            findIfGraphIsBipartite(i, 1);
            connectedComponents++;
        }
    }
    //FIND IF GRAPH IS BIPARTITE END

    /*
     * APPLY SPECIFIC METHOD
     * */

    //PRINT SOLUTION START
    if (ans) {
        cout << "BIPARTITE"
    } else {
        cout << "NOT BIPARTITE";
    }
    cout << endl;
    //PRINT SOLUTION END

    return 0;
}