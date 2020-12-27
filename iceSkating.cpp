/* Connected Components Template
 *
 * What helps recognise that a problem needs connected components?
 * Connected component problems will usually fall into one of the following categories:
 * - We have COORDINATES and RANGES and two coordinates are IN RANGE if they are within
 * a certain range (here IN RANGE means connected)
 * - We have OBJECTS and OTHER OBJECTS and we can CONNECT different OBJECTS by using
 * OTHER OBJECTS (a common example of this is cities and roads)
 * - We have NODES and EDGES and NODES are CONNECTED by EDGES (here we can see that this
 * is the same as the previous problem, but it is more obvious we need to use a graph)
 *
 * A problem will then specify exactly what they want you to do now that you know you
 * need to store your data using a connected component. This could require you to use
 * MST, Union Find Structure (UFS), DFS, BFS or simply use the number of connected
 * components to find your answer.
 *
 * Please note that this template is for the second and third types of problems
 * mentioned above. Another template is needed for the first type of problem I showed
 *
 * This is for COORDINATES and RANGES.
 */


#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5; //max n we can have

int n, k;
int connectedComponents;
int xCoordinates[N];
int yCoordinates[N];
int visited[N];

vector <int> graph[N]; //index 1 corresponds to index 1 in both array coordinates

void findNumberOfConnectedComponents(int currentNode) {
    visited[currentNode] = 1;

    for (auto to : graph[currentNode]) {
        if (!visited[to]) {
            findNumberOfConnectedComponents(to);
        }
    }
}

int main() {

    //INPUT START
    cin >> n;

    //cin >> k; //might need to take in a number for a specific range

    for (int i = 0; i < n; i++) {
        cin >> xCoordinates[i] >> yCoordinates[i];

        //BUILDING GRAPH START
        for (int j = 0; j < i; j++) {
            if (xCoordinates[i] == xCoordinates[j] || yCoordinates[i] == yCoordinates[j]) { //if they meet certain condition/range
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
        //BUILDING GRAPH END
    }
    //INPUT END


    //FIND NUMBER OF COMPONENTS START
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            findNumberOfConnectedComponents(i);
            connectedComponents++;
        }
    }
    //FIND NUMBER OF COMPONENTS END

    /*
     * APPLY SPECIFIC METHOD
     * Now that we have our CCs, we can apply specific methods/calculations to the
     * problem, e.g. we may need to use Union Find Structure in order to merge CCs
     * */

    //PRINT SOLUTION START
    cout << connectedComponents - 1; //e.g. I can print the number of CCs
    //PRINT SOLUTION END

    return 0;
}