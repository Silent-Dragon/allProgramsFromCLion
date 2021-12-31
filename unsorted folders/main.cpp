#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>

using namespace std;

stack <int> mp;
int main() {
/*
//Spammer

    int n;

//Number of submissions
    cin >> n;

    string a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map <string, int> m;

    for (int i = 0; i < n; i++) {
        m[a[i]] = m[a[i]] + 1;
    }



    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > 1) {
            cout << it->first << endl;
        }
    }





    // MATRIX

    // declaring the 2d array
    int a[6][6];

    //each row
    for (int row = 1; row <=5; row++) {
        //each column
        for (int column = 1; column <= 5; column++) {
            //here we get the inputs for the array
            cin >> a[row][column];
        }
    }

    for (int row = 1; row <= 5; row++) {
        //each column
        for (int column = 1; column <= 5; column++) {
            if (a[row][column] == 1) {
                cout << abs(3 - row) + abs(3 - column);
            }
        }
    }

*/




    //Football





//THEATRE SQUARE
//

    /*   int n;
       int m;
       int a;
       int count = 0;
       int remainingAreaOfSquare;

       cin >> m; //width
       cin >> n; //length
       cin >> a; //sideOfFlagstone

       while (n <= 1 && m <= 1 && a >= pow(10, 9)) {
           cout << "Incorrect input, please try again";
           cin >> m; //width
           cin >> n; //length
           cin >> a; //sideOfFlagstone
       }

       int areaOfFlagstone = a * a;

       while (n % a != 0) {
           n ++;
       }

       while (m % a != 0) {
           m ++;
       }

       remainingAreaOfSquare = n * m;

       while (remainingAreaOfSquare > 0) {
           remainingAreaOfSquare = remainingAreaOfSquare - areaOfFlagstone;
           count++;
       }

       cout << count;



    int numberOfMoves = 0;
    int numberOfDisks;
    char currentCode;
    char correctCode;

    cin >> numberOfDisks;
    cin >> currentCode;
    cin >> correctCode;



    for (int i = 0; i <= numberOfDisks; i++) {
        currentCode[i] = currentCode[i] - '0';
        correctCode[i] = correctCode[i] - '0';
        cout << abs(currentCode[i] - correctCode[i]) << endl;
        numberOfMoves += abs(currentCode[i] - correctCode[i]);
        cout << numberOfMoves << endl;
    }

    cout << numberOfMoves;
*/


    int n;
    int ans = 0;
    int cnt = 0;
    cin >> n;
    char s[100];
    int num;
    for (int i = 0; i < 2 * n; i++) {
        cin >> s;
        if (s[0] == 'a') {
            cin >> num;
            mp.push(num);
        }
        else {
            ans++;
            if (mp.empty()) continue;
            else {
                if (mp.top() == ans)
                    mp.pop();
                else {
                    cnt++;
                    while (!mp.empty())
                    {
                        mp.pop();
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;

}