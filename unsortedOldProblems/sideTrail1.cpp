#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int t = 0;
int m = 0;
int cnt = 0;
int I = 0;
int J = 0;
string a;
int maze[21][21];
vector <int> trail;

void move(int i, int j, char heading, int moves) {

    if (j - 1 > -1 && maze[i][j - 1] == 0 && heading == 'U') {
        maze[i][j] = 1;
        J -= 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading U, 1. Cnt: " << cnt << endl;
        move(i, j - 1, 'L', cnt);
    } else if (i - 1 > -1 && maze[i - 1][j] == 0 && heading == 'U') {
        maze[i][j] = 1;
        I -= 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading U, 2. Cnt: " << cnt << endl;
        move(i - 1, j, 'U', cnt);
    } else if (j + 1 < 21 && maze[i][j + 1] == 0 && heading == 'U') {
        maze[i][j] = 1;
        J += 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading U, 3. Cnt: " << cnt << endl;
        move(i, j + 1, 'D', cnt);
    } else if (i + 1 < 21 && maze[i + 1][j] == 0 && heading == 'U') {
        maze[i][j] = 1;
        I += 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading U, 4. Cnt: " << cnt << endl;
        move(i + 1, j, 'D', cnt);
    }

    if (i + 1 < 21 && maze[i + 1][j] == 0 && heading == 'L') {
        maze[i][j] = 1;
        I += 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading L, 1. Cnt: " << cnt << endl;
        move(i + 1, j, 'D', cnt);
    } else if (j - 1 > -1 && maze[i][j - 1] == 0 && heading == 'L') {
        maze[i][j] = 1;
        J -= 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading L, 2. Cnt: " << cnt << endl;
        move(i, j - 1, 'L', cnt);
    } else if (i - 1 > -1 && maze[i - 1][j] == 0 && heading == 'L') {
        maze[i][j] = 1;
        I -= 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading L, 3. Cnt: " << cnt << endl;
        move(i - 1, j, 'U', cnt);
    } else if (j + 1 < 21 && maze[i][j + 1] == 0 && heading == 'L') {
        maze[i][j] = 1;
        J += 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading L, 4. Cnt: " << cnt << endl;
        move(i, j + 1, 'R', cnt);
    }

    if (i - 1 > -1 && maze[i - 1][j] == 0 && heading == 'R') {
        maze[i][j] = 1;
        I -= 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading R, 1. Cnt: " << cnt << endl;
        move(i - 1, j, 'U', cnt);
    } else if (j + 1 < 21 && maze[i][j + 1] == 0 && heading == 'R') {
        maze[i][j] = 1;
        J += 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading R, 2. Cnt: " << cnt << endl;
        move(i, j + 1, 'R', cnt);
    } else if (i + 1 < 21 && maze[i + 1][j] == 0 && heading == 'R') {
        maze[i][j] = 1;
        I += 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading R, 3. Cnt: " << cnt << endl;
        move(i + 1, j, 'D', cnt);
    } else if (j - 1 > -1 && maze[i][j - 1] == 0 && heading == 'R') {
        maze[i][j] = 1;
        J -= 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading R, 4. Cnt: " << cnt << endl;
        move(i, j - 1, 'U', cnt);
    }

    if (j + 1 < 21 && maze[i][j + 1] == 0 && heading == 'D') {
        maze[i][j] = 1;
        J += 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading D, 1. Cnt: " << cnt << endl;
        move(i, j + 1, 'R', cnt);
    } else if (i + 1 < 21 && maze[i + 1][j] == 0 && heading == 'D') {
        maze[i][j] = 1;
        I += 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading D, 2. Cnt: " << cnt << endl;
        move(i + 1, j, 'D', cnt);
    } else if (j - 1 > -1 && maze[i][j - 1] == 0 && heading == 'D') {
        maze[i][j] = 1;
        J -= 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading D, 3. Cnt: " << cnt << endl;
        move(i, j - 1, 'L', cnt);
    } else if (i - 1 > -1 && maze[i - 1][j] == 0 && heading == 'D') {
        maze[i][j] = 1;
        I -= 1;
        cnt++;

        cout << maze[i][j] << endl;
        cout << "i " << i << " j" << j << endl;
        cout << "L: Heading D, 4. Cnt: " << cnt << endl;
        move(i - 1, j, 'U', cnt);
    }



    cout << "End" << endl;
    cout << cnt;
    exit(0);

}




int main() {
    cin >> a;

    memset(maze, 0, sizeof(maze));

    move(11, 11, 'U', 0);


    return 0;
}