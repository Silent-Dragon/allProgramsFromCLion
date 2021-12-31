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


long long int n, m;
char a[1000][1000];

long long int d[1000][1000];
//bool visited[1000][1000];
void bfs(int exitX, int exitY) {
    memset(d, -1, sizeof(d));
    /*
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            d[i][j] = -1;
        }
    }*/

    d[exitX][exitY] = 0;
    queue < pair <int, int> > q;
    q.push({exitX, exitY});
    while (q.size() > 0) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        // left
        if (j - 1 >= 1 && d[i][j - 1] == -1 && a[i][j - 1] != 'T') {
            d[i][j - 1] = d[i][j] + 1;
            q.push({i,j - 1});
        }
        // right
        if (j + 1 <= m && d[i][j + 1] == -1 && a[i][j + 1] != 'T') {
            d[i][j + 1] = d[i][j] + 1;
            q.push({i, j + 1});
        }
        // up
        if (i - 1 >= 1 && d[i - 1][j] == -1 && a[i - 1][j] != 'T') {
            d[i - 1][j] = d[i][j] + 1;
            q.push({i - 1, j});
        }
        // down
        if (i + 1 <= n && d[i + 1][j] == -1 && a[i + 1][j] != 'T') {
            d[i + 1][j] = d[i][j] + 1;
            q.push({i + 1, j});
        }
    }
    int distToUs = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'S') {
                distToUs = d[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i][j] != -1 && isdigit(a[i][j]) && d[i][j] <= distToUs) {
                ans += a[i][j] - '0';
            }
        }
    }
    cout << ans;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen ("in.txt", "r", stdin);

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'E') {
                bfs(i, j);
            }
        }
    }
    return 0;
}