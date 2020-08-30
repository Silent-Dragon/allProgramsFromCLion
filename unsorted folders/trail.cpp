#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int t, m, cnt, I, J;
string a;
int maze[10000][10000];
vector <int> trail;

void move(int i, int j, char heading, char direction, int moves, int position) {
    if (cnt == m) {
        cout << "Moves completed" << endl;
        cout << "(" << 0 + I << ", " << 0 + J << ")";
        exit(0);
    }

    if (direction == 'R') {

        if (!isdigit(maze[i][j + 1]) && heading == 'U') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i, j + 1, 'R', a[position], cnt, position);
        } else if (!isdigit(maze[i + 1][j]) && heading == 'U') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i + 1, j, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i][j - 1]) && heading == 'U') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i, j - 1, 'L', a[position], cnt, position);
        } else if (!isdigit(maze[i - 1][j]) && heading == 'U') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i - 1, j, 'U', a[position], cnt, position);
        }

        if (!isdigit(maze[i - 1][j]) && heading == 'L') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i - 1, j, 'U', a[position], cnt, position);
        } else if (!isdigit(maze[i][j + 1]) && heading == 'L') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i, j + 1, 'R', a[position], cnt, position);
        } else if (!isdigit(maze[i + 1][j]) && heading == 'L') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i + 1, j, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i][j - 1]) && heading == 'L') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i, j - 1, 'L', a[position], cnt, position);
        }

        if (!isdigit(maze[i + 1][j]) && heading == 'R') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i + 1, j, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i][j - 1]) && heading == 'R') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i, j - 1, 'L', a[position], cnt, position);
        } else if (!isdigit(maze[i - 1][j]) && heading == 'R') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i - 1, j, 'U', a[position], cnt, position);
        } else if (!isdigit(maze[i][j + 1]) && heading == 'R') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i, j + 1, 'R', a[position], cnt, position);
        }


        if (!isdigit(maze[i][j - 1]) && heading == 'D') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i, j - 1, 'L', a[position], cnt, position);
        } else if (!isdigit(maze[i - 1][j]) && heading == 'D') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i - 1, j, 'U', a[position], cnt, position);
        } else if (!isdigit(maze[i][j + 1]) && heading == 'D') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i, j + 1, 'R', a[position], cnt, position);
        } else if (!isdigit(maze[i + 1][j]) && heading == 'D') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            move(i + 1, j, 'R', a[position], cnt, position);
        }


    }

    if (direction == 'F') {

        if (!isdigit(maze[i - 1][j]) && heading == 'U') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }

            cout << "F: Heading U, 1" << endl;
            move(i - 1, j, 'U', a[position], cnt, position);
        } else if (!isdigit(maze[i][j + 1]) && heading == 'U') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading U, 2" << endl;
            move(i, j + 1, 'R', a[position], cnt, position);
        } else if (!isdigit(maze[i + 1][j]) && heading == 'U') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading U, 3" << endl;
            move(i + 1, j, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i][j - 1]) && heading == 'U') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading U, 4" << endl;
            move(i, j - 1, 'L', a[position], cnt, position);
        }

        if (!isdigit(maze[i][j - 1]) && heading == 'L') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J-= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading L, 1" << endl;
            move(i, j - 1, 'L', a[position], cnt, position);
        } else if (!isdigit(maze[i - 1][j]) && heading == 'L') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading L, 2" << endl;
            move(i - 1, j, 'U', a[position], cnt, position);
        } else if (!isdigit(maze[i][j + 1]) && heading == 'L') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading L, 3" << endl;
            move(i, j + 1, 'R', a[position], cnt, position);
        } else if (!isdigit(maze[i + 1][j]) && heading == 'L') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading L, 4" << endl;
            move(i + 1, j, 'D', a[position], cnt, position);
        }

        if (!isdigit(maze[i][j + 1]) && heading == 'R') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading R, 1" << endl;
            move(i, j + 1, 'R', a[position], cnt, position);
        } else if (!isdigit(maze[i + 1][j]) && heading == 'R') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading R, 2" << endl;
            move(i + 1, j, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i][j - 1]) && heading == 'R') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading R, 3" << endl;
            move(i, j - 1, 'L', a[position], cnt, position);
        } else if (!isdigit(maze[i - 1][j]) && heading == 'R') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading R, 4" << endl;
            move(i - 1, j, 'U', a[position], cnt, position);
        }


        if (!isdigit(maze[i + 1][j]) && heading == 'D') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading D, 1" << endl;
            move(i + 1, j, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i][j - 1]) && heading == 'D') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading D, 2" << endl;
            move(i, j - 1, 'L', a[position], cnt, position);
        } else if (!isdigit(maze[i - 1][j]) && heading == 'D') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading D, 3" << endl;
            move(i - 1, j, 'U', a[position], cnt, position);
        } else if (!isdigit(maze[i][j + 1]) && heading == 'D') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "F: Heading D, 4" << endl;
            move(i, j + 1, 'R', a[position], cnt, position);
        }


    }

    if (direction == 'L') {

        if (!isdigit(maze[i][j - 1]) && heading == 'U') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading U, 1" << endl;
            move(i, j - 1, 'L', a[position], cnt, position);
        } else if (!isdigit(maze[i - 1][j]) && heading == 'U') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading U, 2" << endl;
            move(i - 1, j, 'U', a[position], cnt, position);
        } else if (!isdigit(maze[i][j + 1]) && heading == 'U') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading U, 3" << endl;
            move(i, j + 1, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i + 1][j]) && heading == 'U') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading U, 4" << endl;
            move(i + 1, j, 'D', a[position], cnt, position);
        }

        if (!isdigit(maze[i + 1][j]) && heading == 'L') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading L, 1" << endl;
            move(i + 1, j, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i][j - 1]) && heading == 'L') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading L, 2" << endl;
            move(i, j - 1, 'L', a[position], cnt, position);
        } else if (!isdigit(maze[i - 1][j]) && heading == 'L') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading L, 3" << endl;
            move(i - 1, j, 'U', a[position], cnt, position);
        } else if (!isdigit(maze[i][j + 1]) && heading == 'L') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading L, 4" << endl;
            move(i, j + 1, 'R', a[position], cnt, position);
        }

        if (!isdigit(maze[i - 1][j]) && heading == 'R') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading R, 1" << endl;
            move(i - 1, j, 'U', a[position], cnt, position);
        } else if (!isdigit(maze[i][j + 1]) && heading == 'R') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading R, 2" << endl;
            move(i, j + 1, 'R', a[position], cnt, position);
        } else if (!isdigit(maze[i + 1][j]) && heading == 'R') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading R, 3" << endl;
            move(i + 1, j, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i][j - 1]) && heading == 'R') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading R, 4" << endl;
            move(i, j - 1, 'U', a[position], cnt, position);
        }

        if (!isdigit(maze[i][j + 1]) && heading == 'D') {
            trail.push_back(i);
            trail.push_back(j + 1);
            maze[i][j] = 1;
            J += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading D, 1" << endl;
            move(i, j + 1, 'R', a[position], cnt, position);
        } else if (!isdigit(maze[i + 1][j]) && heading == 'D') {
            trail.push_back(i + 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I += 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading D, 2" << endl;
            move(i + 1, j, 'D', a[position], cnt, position);
        } else if (!isdigit(maze[i][j - 1]) && heading == 'D') {
            trail.push_back(i);
            trail.push_back(j - 1);
            maze[i][j] = 1;
            J -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading D, 3" << endl;
            move(i, j - 1, 'L', a[position], cnt, position);
        } else if (!isdigit(maze[i - 1][j]) && heading == 'D') {
            trail.push_back(i - 1);
            trail.push_back(j);
            maze[i][j] = 1;
            I -= 1;
            cnt++;
            if (trail.size() > t) {
                maze[trail[0]][trail[1]] = ' ';
                trail.erase(trail.begin());
                trail.erase(trail.begin());
            }

            if (position > a.size()) {
                position = 0;
            } else {
                position++;
            }
            cout << "L: Heading D, 4" << endl;
            move(i - 1, j, 'U', a[position], cnt, position);
        }


    }

    cout << "Stuck" << endl;
    cout << "(" << 0 + I << ", " << 0 + J << ")";
    exit(0);

}




int main() {
    cin >> t >> a >> m;

    move(5000, 5000, 'U', a[0], 0, 0);


    return 0;
}