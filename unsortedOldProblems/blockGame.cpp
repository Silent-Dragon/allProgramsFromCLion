#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int blocksNeeded[26];


//This function takes in a string and returns an integer array of the number of blocks needed to spell out the given word.
 vector <int> getFrequency(string s) {

    vector <int> a(26);
/*
    for (int i = 0; i < 26; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
*/
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        a[index]++;
    }

    return a;
}

int main() {
        freopen("blocks.in", "r", stdin);
        freopen("blocks.out", "w", stdout);
       // freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);

        // read in the number of blocks
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            // read in each pair of words
            string firstWord, secondWord;
            cin >> firstWord >> secondWord;

            vector <int> firstFrequency = getFrequency(firstWord);
            vector <int> secondFrequency = getFrequency(secondWord);

            // update the number of blocks needed
            for (int j = 0; j < 26; j++) {
                if (firstFrequency[j] > secondFrequency[j]) {
                    blocksNeeded[j] += firstFrequency[j];
                } else {
                    blocksNeeded[j] += secondFrequency[j];
                }
            }
        }

        // print the answer
        for (int i = 0; i < 26; i++) {
            cout << blocksNeeded[i];
            cout << endl;
        }

        return 0;
}


