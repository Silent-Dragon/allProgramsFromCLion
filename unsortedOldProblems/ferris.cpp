#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n = 0; //no. children
int x = 0; //max allowed weight
vector <int> originalWeightsOfChildren;
multiset <int> freeWeightsOfChildren;

int pods = 0; //no. gondolas used
int desiredWeight = 0; // the weight that would be the perfect match for our number
multiset <int>::iterator complimentingWeightPointer;

int main() {
   // freopen("in.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;


    for (int i = 0; i < n; i++) {
        int m = 0;
        cin >> m;
        originalWeightsOfChildren.push_back(m);
        freeWeightsOfChildren.insert(m);
    }

    sort(originalWeightsOfChildren.begin(), originalWeightsOfChildren.end());

    while (freeWeightsOfChildren.size() > 0) {
        desiredWeight = x - *freeWeightsOfChildren.begin();
        freeWeightsOfChildren.erase(freeWeightsOfChildren.begin());


        // Note on indexes: lower bound indexes start at 1 and array indexes start at 0, so deduct 1 from the result of lower bound
        // Note on lower bound use: we run lower bound on the desiredWeight + 1 to get the desiredWeight if it exists


        complimentingWeightPointer = freeWeightsOfChildren.lower_bound(desiredWeight + 1);
        if (complimentingWeightPointer != freeWeightsOfChildren.begin()) {
            complimentingWeightPointer--;
            freeWeightsOfChildren.erase(complimentingWeightPointer);
            /*
                complimentingWeightPointer == freeWeightsOfChildren.begin()
                complimentingWeightPointer--
            */
            //freeWeightsOfChildren.erase(freeWeightsOfChildren.begin() + complimentingWeightIndex);
        }

        // increase pods used
        pods++;
    }

    cout << pods << endl;

    return 0;
}