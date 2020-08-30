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

const int N = (int)1e5 + 1;

int n, m, currentNode, discountUsed;
long long int distanceForCurrentNode;
vector <pair <int, int>> graph[N];
long long int distanceForNode[N][2]; //first is node, second is whether we have used a discount or not so far
set <pair <pair <long long int, int>, int>> shortestDistance; //distance, node, used

void dijakstra (int node) {
    shortestDistance.insert({{0, node}, 0});
    //add node to set

    distanceForNode[node][0] = 0;
    //distance for currentnode is 0

    while (!shortestDistance.empty()) {
        currentNode = shortestDistance.begin()->first.second;
        //currentNode = beginning of set

        discountUsed = shortestDistance.begin()->second;
        //discountused = beginning of set (discount used or not)

        distanceForCurrentNode = shortestDistance.begin()->first.first;
        //distanceForCurrentNode = beginning of set

        shortestDistance.erase(shortestDistance.begin());
        //remove current beginning node/distance from set

        for (auto itr : graph[currentNode]) {
            //currentdistance + connection < connectingnodedistance
            if (distanceForNode[currentNode][discountUsed] + itr.second < distanceForNode[itr.first][discountUsed]) {
                shortestDistance.erase({{distanceForNode[itr.first][discountUsed], itr.first}, discountUsed});
                //remove old distance from set
                distanceForNode[itr.first][discountUsed] = distanceForNode[currentNode][discountUsed] + itr.second;
                //update connecting node distance
                shortestDistance.insert({{distanceForNode[itr.first][discountUsed], itr.first}, discountUsed});
                //add new distance to set and discount (whatever it has so far)
            }

           if (discountUsed == 0) {
                //currentdistance + (connection / 2) < connectingnodedistance
                if (distanceForNode[currentNode][0] + (itr.second / 2) < distanceForNode[itr.first][1]) {
                    shortestDistance.erase({{distanceForNode[itr.first][1], itr.first}, 1});
                    //remove old distance from set
                    distanceForNode[itr.first][1] = distanceForNode[currentNode][discountUsed] + (itr.second / 2);
                    //update connecting node distance
                    shortestDistance.insert({{distanceForNode[itr.first][1], itr.first}, 1});
                    //add new distance to set and discount used
                }
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int startNode;
        int endNode;
        int length;

        cin >> startNode >> endNode >> length;

        graph[startNode].push_back({endNode, length});

        startNode = 0;
        endNode = 0;
        length = 0;
    }

    for (int i = 1; i <= n; i++) {
        distanceForNode[i][0] = 1e15;
        distanceForNode[i][1] = 1e15;
    }

    dijakstra(1);

    //cout << distanceForNode[n][0] << endl;
    cout << distanceForNode[n][1] << endl;

    return 0;
}
