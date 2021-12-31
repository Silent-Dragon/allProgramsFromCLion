#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int t, m;
string a;

// int maze[20000][20000];
// 10000 * 10000 = 1e8
/*
    (n * 4) / 1024^2

    1 ~ 4 bytes
    1024 bytes ~ 1 kb
    1024 kb ~ 1 mb
*/

/*
 t <= 100
 s <= 10
 m <= 10000
*/

map < pair <int, int> , int> maze;

vector <int> trail;

// L, U, R, D
int di[] = {0, +1, 0, -1};
int dj[] = {-1, 0, +1, 0};


void move(int i, int j, int heading, int moves, int position) {
    if (position == a.size()) {
        position = 0;
    }
    maze[{i, j}] = 1;
    if (trail.size() > t) {
        // maze[trail[0]][trail[1]] = 0;
        maze.erase({trail[0], trail[1]});
        trail.erase(trail.begin());
        trail.erase(trail.begin());
    }
    if (moves == m) {
        cout << "Moves completed" << endl;
        cout << "(" << j << ", " << i << ")";
        exit(0);
    }

    if (a[position] == 'R') {
        heading = (heading + 1) % 4;
        for (int z = 1; z <= 4; z++) {
            int ni = i + di[heading];
            int nj = j + dj[heading];
            if (!maze.count({ni, nj})) {
                move(ni, nj, heading, moves + 1, position + 1);
            }
            heading = (heading + 1) % 4;
        }
    }

    if (a[position] == 'F') {
        heading = heading % 4;
        for (int z = 1; z <= 4; z++) {
            int ni = i + di[heading];
            int nj = j + dj[heading];
            if (!maze.count( {ni, nj} )) {
                move(ni, nj, heading, moves + 1, position + 1);
            }
            heading = (heading + 1) % 4;
        }
    }


    if (a[position] == 'L') {
        heading = (heading + 3) % 4;
        for (int z = 1; z <= 4; z++) {
            int ni = i + di[heading];
            int nj = j + dj[heading];
            if (!maze.count({ni, nj})) {
                move(ni, nj, heading, moves + 1, position + 1);
            }
            heading = (heading + 1) % 4;
        }
    }

    cout << "Stuck" << endl;
    cout << "(" << j << ", " << i << ")";
    exit(0);

}




int main() {
    cin >> t >> a >> m;

    move(0, 0, 1, 0, 0);


    return 0;
}