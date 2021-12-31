#include <iostream>
#include <set>

using namespace std;

/// O(n! * log(n))
///permutations * set

string myString, permutation;
set <string> allPermutations;
int chosen[1000];
int value;

void search() {
    if (permutation.size() == myString.size()) {
        // a full permutation has now been generated
        allPermutations.insert(permutation);
    } else {
        for (int i = 0; i < myString.size(); i++) {
            if (chosen[i]) {
                continue;
            }
            chosen[i] = true;
            permutation.push_back(myString[i]);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
///Input
    cin >> myString;

///Method
    //cout << "Going to generate permutations." << endl;
    search();

///Result
    //cout << "Number of permutations generated is " << allPermutations.size() << "." << endl;
    cout << allPermutations.size() << endl;
    for (auto itr = allPermutations.begin(); itr != allPermutations.end(); ++itr) {
        cout << *itr << endl; //this prints the item of the set in the current place
    }

    return 0;
}