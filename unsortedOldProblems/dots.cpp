#include <iostream>
#include <vector>
#include <map>

using namespace std;

int currentPosition1 = 0;
int currentPosition2 = 0;
int modifier1 = 0;
int modifier2 = 0;
int moves = 0;
int movesCompleted = 0;
map < pair <int, int>, int> visitedEdges;
int finalBoard[5][5];
int player1Squares = 0;
int player2Squares = 0;

bool isNoEdge(int currentPosition, int nextPosition) {
    if (visitedEdges.count({currentPosition, nextPosition}) && visitedEdges.count({nextPosition, currentPosition})) {
        return false;
    } else {
        return true;
    }
}

bool completeSquare(int point1, int point2, int player) {
    //my two points are both connected to two other points
    // if current edge is up or down -- check left and right
    // if current edge is left or right -- check up and down
    if (abs(point1 - point2) == 1) { //left or right
        //check down
        if (point1 < 31 && point2 < 31) { //max(point1, point2) < 31
            if (!isNoEdge(point1, point1 + 6) && !isNoEdge(point2, point2 + 6) && !isNoEdge(point1 + 6, point2 + 6)) {
                return true;
            }
        }
        //check up
        if (point1 > 6 && point2 > 6) {
            if (!isNoEdge(point1, point1 - 6) && !isNoEdge(point2, point2 - 6) && !isNoEdge(point1 - 6, point2 - 6)) {
                return true;
            }
        }
    } else { //up or down
        //check left
        if (point1 % 6 != 1 && point2 % 6 != 1) {
            if (!isNoEdge(point1, point1 - 1) && !isNoEdge(point2, point2 - 1) && !isNoEdge(point1 - 1, point2 - 1)) {
                return true;
            }
        }
        //check right
         if (point1 % 6 != 0 && point2 % 6 != 0) {
             if (!isNoEdge(point1, point1 + 1) && !isNoEdge(point2, point2 + 1) && !isNoEdge(point1 + 1, point2 + 1)) {
                 return true;
             }
         }
    }

    return false;
}

void movePlayer(int player) {
    int nextPosition2 = 0;
    int nextPosition1 = 0;
    movesCompleted++;
    if (movesCompleted == moves || visitedEdges.size() == 120) {
        cout << "Done" << endl;
        cout << "Number of moves: " << movesCompleted;
        return;
    }

    if (player == 2) {
        cout << "Current position2: " << currentPosition2 << endl;
        currentPosition2 += modifier2;
        if (currentPosition2 > 36) {
            currentPosition2 %= 36;
        }
        if (currentPosition2 > 6 && isNoEdge(currentPosition2, currentPosition2 - 6)) {
            visitedEdges[{currentPosition2, currentPosition2 - 6}] = 1;
            visitedEdges[{currentPosition2 - 6, currentPosition2}] = 1;
            nextPosition2 = currentPosition2 - 6;
        } else if (currentPosition2 % 6 != 1 && isNoEdge(currentPosition2, currentPosition2 - 1)) {
            //try left
            visitedEdges[{currentPosition2, currentPosition2 - 1}] = 1;
            visitedEdges[{currentPosition2 - 1, currentPosition2}] = 1;
            nextPosition2 = currentPosition2 - 1;
        } else if (currentPosition2 < 31 && isNoEdge(currentPosition2, currentPosition2 + 6)) {
            //else try down
            visitedEdges[{currentPosition2, currentPosition2 + 6}] = 1;
            visitedEdges[{currentPosition2 + 6, currentPosition2}] = 1;
            nextPosition2 = currentPosition2 + 6;
        } else if (currentPosition2 % 6 != 0 && isNoEdge(currentPosition2, currentPosition2 + 1)) {
            //else try right
            visitedEdges[{currentPosition2, currentPosition2 + 1}] = 1;
            visitedEdges[{currentPosition2 + 1, currentPosition2}] = 1;
            nextPosition2 = currentPosition2 + 1;
        } else {
            // else currentPosition2++ and repeat above
            movesCompleted--;
            currentPosition2++;
            movePlayer(2);
            return;
        }

        if (completeSquare(currentPosition2, nextPosition2, 2)) {
            player2Squares++;
            movePlayer(2);
        } else {
            player1Squares++;
            movePlayer(1);
        }
    }

    if (player == 1) {
        cout << "Current position1: " << currentPosition1 << endl;
        currentPosition1 += modifier1;
            if (currentPosition1 > 36) {
                currentPosition1 %= 36;
            }
            if (currentPosition1 > 6 && isNoEdge(currentPosition1, currentPosition1 - 6)) {
                visitedEdges[{currentPosition1, currentPosition1 - 6}] = 1;
                visitedEdges[{currentPosition1 - 6, currentPosition1}] = 1;
                nextPosition1 = currentPosition1 - 6;
            } else if (currentPosition1 % 6 != 1 && isNoEdge(currentPosition1, currentPosition1 - 1)) {
                //try left
                visitedEdges[{currentPosition1, currentPosition1 - 1}] = 1;
                visitedEdges[{currentPosition1 - 1, currentPosition1}] = 1;
                nextPosition1 = currentPosition1 - 1;
            } else if (currentPosition1 < 31 && isNoEdge(currentPosition1, currentPosition1 + 6)) {
                //else try down
                visitedEdges[{currentPosition1, currentPosition1 + 6}] = 1;
                visitedEdges[{currentPosition1 + 6, currentPosition1}] = 1;
                nextPosition1 = currentPosition1 + 6;
            } else if (currentPosition1 % 6 != 0 && isNoEdge(currentPosition1, currentPosition1 + 1)) {
                //else try right
                visitedEdges[{currentPosition1, currentPosition1 + 1}] = 1;
                visitedEdges[{currentPosition1 + 1, currentPosition1}] = 1;
                nextPosition1 = currentPosition1 + 1;
            } else {
                // else currentPosition1++ and repeat above
                movesCompleted--;
                currentPosition1++;
                movePlayer(1);
                return;
            }
        }

        if (completeSquare(currentPosition1, nextPosition1, 1)) {
            player1Squares++;
            movePlayer(1);
        } else {
            player2Squares++;
            movePlayer(2);
        }
}

int main() {
    cin >> currentPosition1 >> modifier1 >> currentPosition2 >> modifier2 >> moves;

    movePlayer(1);
}