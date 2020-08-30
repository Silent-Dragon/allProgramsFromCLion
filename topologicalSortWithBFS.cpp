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

int n, m;
vector <int> list;
int permanentMark[N];
int tempMark[N];
vector <int> graph[N];

/*void bfs(int city) {
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

}*/

void bfs (int node) {
    //cout << "At node " << node << endl;

    if (permanentMark[node] == 1) {
        //cout << "Already finished this node " << node << endl;
        return;
    }

    if (tempMark[node] == 1) {
        //cycle, not possible to sort topologically
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }

    tempMark[node] = 1;

    for (auto itr : graph[node]) {
        dfs(itr);
    }

    tempMark[node] = 0;
    permanentMark[node] = 1;
    list.push_back(node);
    // cout << "Finished node " << node << endl;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int startNode;
        int endNode;

        cin >> startNode >> endNode;

        graph[startNode].push_back(endNode);

        startNode = 0;
        endNode = 0;
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    reverse(list.begin(), list.end());
    for (auto itr : list) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}
