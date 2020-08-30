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

int n, m, queries, k;

int nxt[N];
int weight[N];
//int prevMoveForEachCoordinate[N]

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> queries;

    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    //PROCESS QUERIES AND GET RESULTS FROM COMPUTATION
    for (int q = 1; q <= queries; q++) {
        int startNode, steps, smallestWeight, currentNode;
        cin >> startNode >> steps;

        currentNode = startNode;
        for (int i = 1; i <= steps; i++) {
            if (smallestWeight > weight[currentNode]) {
                smallestWeight = weight[currentNode];
            }

            currentNode = nxt[currentNode];
        }

        cout << currentNode << " " << smallestWeight << endl;
    }
    cout << endl;



    return 0;
}

//FUNCTIONAL GRAPH FAST SOLUTION