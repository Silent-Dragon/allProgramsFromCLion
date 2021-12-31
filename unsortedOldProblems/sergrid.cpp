#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;


int n, m;
int cnt;
int a[1000][1000];

int d[1000][1000];

//bool visited[1000][1000];

void bfs(int exitX, int exitY) {
    memset(d, -1, sizeof(d));

/*    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            d[i][j] = -1;
        }
    }

*/
    d[exitX][exitY] = 0;
    queue <pair <int, int>> q;
    q.push({exitX, exitY});
    while (q.size() > 0) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        /*
        // left
        if (j - a[i][j] >= 1 && d[i][j - 1] == -1) {
            d[i][j - a[i][j]] = d[i][j] + 1;
            cnt++;
            q.push({i, j - a[i][j]});
        }
        // right
        if (j + a[i][j] <= m && d[i][j + 1] == -1) {
            d[i][j + a[i][j]] = d[i][j] + 1;
            cnt++;
            q.push({i, j + a[i][j]});
        }
        // up
        if (i - a[i][j] >= 1 && d[i - 1][j] == -1) {
            d[i - a[i][j]][j] = d[i][j] + 1;
            cnt++;
            q.push({i - a[i][j], j});
        }
        */
        // down
        if (i + a[i][j] <= n && d[i + 1][j] == -1) {
            d[i + a[i][j]][j] = d[i][j] + 1;
            cnt++;
            int p1 = i + a[i][j];
            int p2 = j;
            q.push({p1, p2});
           // while (!q.empty()) {
             //   cout << q.front().first << " " << q.front().second;
               // q.pop();
            }
        }
    }
    //int distToUs = -1;

    //distToUs = d[0][0];

//}

int main() {
    freopen ("in.txt", "r", stdin);

    cout << "Enter n: ";
    cin >> n;
    cout << endl;

    cout << "Enter m: ";
    cin >> m;
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter value for place " << i << ", " << j << ": ";
            cin >> a[i][j];
            cout << endl;
        }
    }

    cout << "Before";
    cout << endl;

    bfs(n - 1, m - 1);

    cout << "After";
    cout << cnt;

    return 0;
}