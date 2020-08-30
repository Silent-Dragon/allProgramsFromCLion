#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0;
string w = "";
string cipherDial = "";
vector <string> cypherDial;
vector <int> deleted(26, 0);

void encryptWord() {
    int charAsNumForKey[26];
 //   memset(charAsNumForKey, 0, sizeof(charAsNumForKey));
    fill(charAsNumForKey, charAsNumForKey + 26, 0);

    int pos = 0;
    for (int I = 0; I < 26; I++) {
        int dist = n;
        while (dist > 0) {
            if (!deleted[pos]) dist--;
            if (dist == 0) break;
            pos++;
            if (pos == 26) pos = 0;
        }
        cipherDial += pos + 'A';
        deleted[pos] = 1;
        pos = (pos + 1) % 26;
    }

    for (int i = 0; i < 26; i++) {
        cout << cipherDial[i];
    }
    cout << endl;

    string encryptedWord = "";

    //cout << cipherDial;
   // cout << endl;


    for (int i = 0; i < 26; i++) {
        string temp;
        temp.push_back(cipherDial[i]);
        cypherDial.push_back(temp);
    }

    int position = 0;

    for (int i = 0; i < w.length(); i++) {
        // A (1) = 0   H (8) = 16
        position = (i + (w[i] - 'A')) % 26;
        encryptedWord += cypherDial[position][0];
       // cout << "Size: " << cypherDial.size() << endl;
        //cout << "Position: " << position << endl;
        //cypherDial.erase(cypherDial.begin() + position);
        cout << encryptedWord[i];
    }
    cout << endl;

}



int main() {
   // freopen("in.txt", "r", stdin);
    double Start = clock();
    cin >> n >> w;

    encryptWord();
    double End = clock();

    cerr << endl << (End - Start) / CLOCKS_PER_SEC;

    return 0;
}