#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0; //no. children
int x = 0; //max allowed weight
vector <int> weightsOfChildren;

int pods = 0; //no. gondolas used
int cntBackwards = 0;
int desiredWeight = 0; // the weight that would be the perfect match for our number
vector <int>::iterator complimentingWeightIndex;

int main() {
    //freopen("in.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    int allocatedChildrenWeights[n];

    for (int i = 0; i < n; i++) {
        allocatedChildrenWeights[i] = 0;

        int m = 0;
        cin >> m;
        weightsOfChildren.push_back(m);
    }

    sort(weightsOfChildren.begin(), weightsOfChildren.end());

    for (int i = 0; i < n; i++) {
        if (allocatedChildrenWeights[i] == 0) {
            //resetting my backwards moving counter for lower bound re-runs
            cntBackwards = 0;

            allocatedChildrenWeights[i] = 1;

            desiredWeight = x - weightsOfChildren[i];

            // Note on indexes: lower bound indexes start at 1 and array indexes start at 0, so deduct 1 from the result of lower bound
            // Note on lower bound use: we run lower bound on the desiredWeight + 1 to get the desiredWeight if it exists
            complimentingWeightIndex = lower_bound(weightsOfChildren.begin(), weightsOfChildren.end(), desiredWeight + 1) - 1;

            // do not go out of bounds when iterating backwards looking for an unused desiredWeight
            while (complimentingWeightIndex - weightsOfChildren.begin() - cntBackwards >= 0) {
                // check whether desiredWeight is used and we need to go backwards
                if (allocatedChildrenWeights[complimentingWeightIndex - weightsOfChildren.begin() - cntBackwards] == 1) {
                    cntBackwards++;
                } else {
                    allocatedChildrenWeights[complimentingWeightIndex - weightsOfChildren.begin() - cntBackwards] = 1;
                    break;
                }
            }
            // increase pods used
            pods++;
        }
    }

    cout << pods << endl;

    return 0;
}