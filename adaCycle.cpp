#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = (int)1e9 + 7;
const int N = 2000;

int n;
vector <int> g[N];
bool a[2000][2000];
int d[2000];
/*
    n - # number of nodes
    m - # number of edges
*/
bool visited[N];
// visited[v] = 1

void bfs(int city) {
    //Here I set every cell in my array visited to -1. This is because I can mark a cell as visited/not visited later on.
    memset(visited, 0, sizeof(visited));
    memset(d, -1, sizeof(d));

    //Here I am saving the current city I am in in my array visited as 'visited' (0)
    visited[city] = 1;
    d[city] = 0;

    //Here I initialise my queue 'q'
    queue <int> q;

    //Here I am pushing my current coordinates into q
    q.push(city);

    //While I have a value/values inside my queue, I continue iterating though the loop
    while (!q.empty()) {
        //Here I set currentCity to my current city
        int currentCity = q.front();

        /*Here I need to iterate through my matrix and see if I have a connection between my current city and another city
         * If I have a connection (1), then I add the cities to my 'cities to check' and continue
         * I will not run into cycles because I will save my current city as visited when I finish finding all the connections
        */

        for (int i = currentCity; i < currentCity + 1; i++) { //then we go to the row of our current city
            for (int j = 0; j < n; j++) { //and we go through all of the columns of that row
                if (a[i][j] == 1 && visited[j] == 0) { //if we have a connection
                    q.push(j);//then we push the city that we can go to into our queue
                    visited[j] = 1; //once we finish we set the current city as visited
                    d[j] = d[i] + 1;//and set the distance to the new city as the distance from our current city + 1
                }
            }
        }

        q.pop();//then we remove our current city from the cities we need to 'check'

    }

}

void path(int start) {
    bfs(start);

    //a[i][start] != a[start][i]
    int minLen = INF;
    for (int i = 0; i < n; i++) {
        if (d[i] != -1 && a[i][start] == 1) {
            minLen = min(minLen, d[i] + 1);
        }
    }

    if (minLen == INF) {
        cout << "NO WAY\n";
    }
    else {
        cout << minLen << "\n";
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

   // freopen ("in.txt", "r", stdin);
    cout << "Enter the number of cities: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //enter either a 1 or 0
            cout << "Enter if there is a path between city " << i << " and " << j << ": ";
            cin >> a[i][j];
            cout << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        path(i);
    }


    return 0;
}
