#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

string inputSerialNumber = " ";
int d = 0;
int cnt;
string newNumber = " ";
//vector <int> visited;
map <string, int> visited;

void buildNewSerialNumber(int i, int distance, string serialNumber) {
    cout << "CHECK" << endl;
    if (i == d - 1) {
        if (cnt != 0) {
            cnt = 0;
            if (!visited.count())
            buildNewSerialNumber(0, distance + 1, serialNumber);
        } else {
            cout << "End" << endl;
            return;
        }

    }

    if (i == 0) {
        if (serialNumber[i + 2] < max(serialNumber[i], serialNumber[i + 1]) && serialNumber[i + 2] > min(serialNumber[i], serialNumber[i + 1]) && !visited.count(serialNumber)) {
            //condition met
            visited.insert({serialNumber, distance});
            swap(serialNumber[i], serialNumber[i + 1]);
        }
    } else if (i == d - 2) {
        if (serialNumber[i - 1] < max(serialNumber[i], serialNumber[i + 1]) && serialNumber[i - 1] > min(serialNumber[i], serialNumber[i + 1]) && !visited.count(serialNumber)) {
            //condition met
            visited.insert({serialNumber, distance});
            swap(serialNumber[i], serialNumber[i + 1]);
            cnt++;
        }
    } else {
         if (!visited.count(serialNumber) && (serialNumber[i - 1] < max(serialNumber[i], serialNumber[i + 1]) && serialNumber[i - 1] > min(serialNumber[i], serialNumber[i + 1])) ||
             (serialNumber[i + 2] < max(serialNumber[i], serialNumber[i + 1]) &&
                     serialNumber[i - 1] > min(serialNumber[i], serialNumber[i + 1]))) {
             //condition met
             visited.insert({serialNumber, distance});
             swap(serialNumber[i], serialNumber[i + 1]);
             cnt++;
         }
     }

     buildNewSerialNumber(i + 1, distance, serialNumber);

}


int main() {
    cin >> d;
    cin >> inputSerialNumber;

    cout << "inputSerialNumber: " << inputSerialNumber << endl;

    buildNewSerialNumber(0, 0, inputSerialNumber);

    int max = 0;
    map<string, int>::iterator itr;
    for (itr = visited.begin(); itr != visited.end(); itr++) {
        if (itr->second > max) {
            max = itr->second;
        }
    }

    cout << max << endl;

    return 0;
}