#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

const int N = (int)2e5 + 7;
long long int n, queries;
long long int a[N];
vector <long long int> ans; //storing the answer for each query here

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

/// Input
    cin >> n >> queries;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

/// Method
    long long int prefixSums[n]; //creating a prefix sums array
    prefixSums[0] = a[0]; //saving the prefix sum for the first place in the array to simply be
    //the value from the original array
    for (int i = 1; i < n; i++) {
        prefixSums[i] = prefixSums[i - 1] + a[i]; //calculating prefix sums for each place in the array
    }

    for (int q = 1; q <= queries; q++) { //now processing queries
        long long int start, end, sum; //creating start and end, the start and end of the
        // current range query
        cin >> start >> end; //taking them in

        //we have to subtract 1 from end and 2 from start to ensure that we are switching from the
        //input being indexed by 1 and indexing by 0 as our arrays are
        if (start == 1) {
            sum = prefixSums[end - 1]; //answer is just the prefix sums of the entire array
        } else {
            sum = prefixSums[end - 1] - prefixSums[start - 2]; //calculating the sum of the range query by
            //using the prefixSums
        }
        ans.push_back(sum); //then adding the answer to ans vector so that the answers can be printed
    }

/// Output
    for (auto itr : ans) {
        cout << itr << endl;
    }
    return 0;
}
