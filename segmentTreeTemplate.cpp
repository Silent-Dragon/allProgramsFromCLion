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

const int N = 1e5; //depends on limits that problem gives you

long long int n;
long long int a[N]; //default array

int queryRight, queryLeft;
long long int st[N * 4]; //segment tree // has a limit of N * 4 which was proved

//indexSt, tl, tr
//max time is n * 4, so time complexity is O(n)
void buildSegmentTree(int indexInST, int leftOfCurrentNode, int rightOfCurrentNode) {
    if (leftOfCurrentNode == rightOfCurrentNode) {
        st[indexInST] = a[leftOfCurrentNode]; //or right
        return; //in a leaf, go back
    }

    int middleOfNextNode = (leftOfCurrentNode + rightOfCurrentNode) / 2;

    buildSegmentTree(indexInST * 2, leftOfCurrentNode, middleOfNextNode); //going left
    buildSegmentTree(indexInST * 2 + 1, middleOfNextNode + 1, rightOfCurrentNode); //going right

    st[indexInST] = st[indexInST * 2] + st[indexInST * 2 + 1]; //sum based on two children
    //if question asked for something other than sum, calculate it here based on children
}

long long int getAnswerForQuery(int leftOfQuery, int rightOfQuery, int indexInST, int leftOfCurrentNode, int rightOfCurrentNode) {
    //FIRST CHECK: is node completely inside range of query
    if (leftOfQuery <= leftOfCurrentNode && rightOfCurrentNode <= rightOfQuery) {
        return st[indexInST]; //function returns answer
    }

    //SECOND CHECK: is node completely outside range of query
    if (rightOfCurrentNode < leftOfQuery || rightOfQuery < leftOfCurrentNode) {
        return 0; //function returns answer, make sure that whatever you return here doesn't affect answer
    }

    //THIRD 'CHECK': node is partly inside range of query
    int middleOfNextNode = (leftOfCurrentNode + rightOfCurrentNode) / 2;

    return getAnswerForQuery(leftOfQuery, rightOfQuery, indexInST * 2, leftOfCurrentNode, middleOfNextNode) + getAnswerForQuery(leftOfQuery, rightOfQuery, indexInST * 2 + 1, middleOfNextNode + 1, rightOfCurrentNode);
    //since we're getting sum, we return the answer we get from each query added to each other
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) { //ST needs to be from 1 and array can be either
        cin >> a[i];
    }
    buildSegmentTree(1, 1, n); //ST needs to be from 1

    cin >> queryRight >> queryLeft;
    cout << getAnswerForQuery(queryRight, queryLeft, 1, 1, n) << endl;

    return 0;
}