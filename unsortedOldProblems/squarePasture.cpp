#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main(){
        freopen("square.in", "r", stdin);
        freopen("square.out", "w", stdout);
        //freopen("in.txt", "r", stdin);

        // track the bottom, top, left, and rightmost points that need to be covered
        int smallestX = 10;
        int largestX = 0;
        int smallestY = 10;
        int largestY = 0;

        // read in two lines, store corners of the pastures
        for (int i = 0; i < 2; i++) {
            int xLow, yLow, xHigh, yHigh;
            cin >> xLow >> yLow >> xHigh >> yHigh;

            if (xLow < smallestX) {
                smallestX = xLow;
            }
            if (xHigh > largestX) {
                largestX = xHigh;
            }
            if (yLow < smallestY) {
                smallestY = yLow;
            }
            if (yHigh > largestY) {
                largestY = yHigh;
            }
        }

        // compute the desired side length of the square
        int sideLengthNeeded = largestX - smallestX;

        if (largestY - smallestY > largestX - smallestX) {
            sideLengthNeeded = largestY - smallestY;
        }

        // print the answer
        cout << sideLengthNeeded * sideLengthNeeded;
        return 0;
}
