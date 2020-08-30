#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 507;

int n, m;
int a[N][N];
int visited[N][N], d[N][N];
int cnt;

void bfs(int exit1, int exit2) {
    //Here I set every cell in my array visited to -1. This is because I can mark a cell as visited/not visited later on.
    memset(visited, -1, sizeof(visited));

    //Here I am saving place exit1, exit2 in my array visited as 'visited' (0)
    visited[exit1][exit2] = 0;
    d[exit1][exit2] = 0;

    //Here I initialise my queue 'q'
    queue <pair <int, int> > q;

    //Here I am pushing my current coordinates into q
    q.push(make_pair(exit1, exit2));

    //While I have a value/values inside my queue, I continue iterating though the loop
    int lastI, lastJ;
    while (!q.empty()) {
        //Here I set i and j to my current coordinates
        int i = q.front().first;
        int j = q.front().second;

        lastI = i;
        lastJ = j;

        //Here I move to the left in my matrix -- I move to the left by the value in my current cell
        //This condition checks that I can move to the left and not go over the boundaries of my matrix, and that I have not visited the cell I am going to
        if (j - a[i][j] >= 0 && visited[i][j - a[i][j]] == -1) {
            visited[i][j - a[i][j]] = 0; // here I set the new coordinates as visited
            d[i][j - a[i][j]] = d[i][j] + 1;
            q.push(make_pair(i, j - a[i][j])); // here I push back the new coordinates
        }

        //Here I move to the right in my matrix -- I move to the right by the value in my current cell
        //This condition checks that I can move to the right and not go over the boundaries of my matrix, and that I have not visited the cell I am going to
        if (j + a[i][j] <= m - 1 && visited[i][j + a[i][j]] == -1) {
            visited[i][j + a[i][j]] = 0; // here I set the new coordinates as visited
            d[i][j + a[i][j]] = d[i][j] + 1;
            q.push(make_pair(i, j + a[i][j])); // here I push back the new coordinates
        }

        //Here I move up in my matrix -- I move up by the value in my current cell
        //This condition checks that I can move up and not go over the boundaries of my matrix, and that I have not visited the cell I am going to
        if (i - a[i][j] >= 0 && visited[i  - a[i][j]][j] == -1) {
            visited[i - a[i][j]][j] = 0; // here I set the new coordinates as visited
            d[i - a[i][j]][j] = d[i][j] + 1;
            q.push(make_pair(i - a[i][j], j)); // here I push back the new coordinates
        }

        //Here I move down in my matrix -- I move down by the value in my current cell
        //This condition checks that I can move down and not go over the boundaries of my matrix, and that I have not visited the cell I am going to
        if (i + a[i][j] <= n - 1     && visited[i + a[i][j]][j] == -1) {
            visited[i + a[i][j]][j] = 0; // here I set the new coordinates as visited
            d[i + a[i][j]][j] = d[i][j] + 1;
            q.push(make_pair(i + a[i][j], j)); // here I push back the new coordinates
        }



        //Here I remove the first element of my queue
        q.pop();
    }

    cout << lastI << ' ' << lastJ;

}


int main() {
    //Here I get my input from file in.text
    freopen ("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //Here I get the value of n, which is the number of rows my 2d array/matrix has
    //cout << "Enter n: ";
    cin >> n;
    //cout << endl;

    //Here I get the value of m, which is the number of columns my 2d array/matrix has
    //cout << "Enter m: ";
    cin >> m;
    //cout << endl;

    //Here I get the value of each cell in my 2d array/matrix. I do this by iterating with the number of rows and columns (n and m) that I have.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout << "Enter value for place " << i << ", " << j << ": ";
            char x;
            cin >> x;
            // a[i][j] -> int
            // char x;
            // (1)(2)34
            a[i][j] = x - '0';
            //cin >> a[i][j];
        }
    }

  //  //Here I check that all my inputs have been successfully saved/given.
 //   cout << "Done with all inputs";
  //  cout << endl;

    //Here I call my function bfs which takes in my starting coordinates which are 0,0 (I go from the top left place in my 2d array/matrix)
    bfs(0, 0);

    //Here I check that I have exited my function
  //  cout << "Exited function";
  //  cout << endl;

   // cout << "Number of moves I did: " << cnt;
  //  cout << endl;

    //Here I am checking that all of my inputs were entered correctly (I have the same values that I entered into in.txt)
    /* cout << n;
     cout << endl;
     cout << m;

     for (int i = 0; i < n; i++) {
         cout << endl;
         for (int j = 0; j < m; j++) {
             cout << "Value in place " << i << ", " << j << ": " << a[i][j];
             cout << " ";
         }
     }
 */
    return 0;
}