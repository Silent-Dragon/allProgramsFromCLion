#include <iostream>
#include <vector>

using namespace std;
const int maxAllowed = 100000;

vector<int>
maxSumSubArrayContiguous(vector <int> & numbers) {
    vector <int> ret(2);
    int sum = 0;
    int maxSum = 0;
    int maxSumNC = 0;
    vector <int> i = 0;
    int allNegative = 1
    int allNegativeMin = numbers[0];

    maxSum = numbers[i];
    for (i = 0; i != numbers.size(); i++) {
        sum += numbers[i];
        if (sum < 0) {
            sum = 0;
        }
        else if (sum > maxSum) {
            maxSum = sum;
        }

        if (numbers[i] >= 0) {
            allNegative = 0;
            maxSumNC += numbers[i];
        } else {
            if (allNegativeMin < numbers[i]) {
                allNegativeMin = numbers[i];
            }
        }
    }

    if (allNegative) {
        ret[0] = allNegativeMin;
        ret[1] = allNegativeMin;
    } else {
        ret[0] = maxSum;
        ret[1] = maxSumNC;
    }

    return ret;
}

int main(void) {
    int numTestCases;
    int N;

    cin >> numTestCases;
    while (numTestCases--) {
        cin >> N;
        vector<int> numbers;
        numbers.clear();
        while (N--) {
            int x;
            cin >> x;
            if (x > maxAllowed) {
                cout << "Invalid Input" << endl;
                break;
            }
            numbers.push_back(x);
        }

        vector <int> ret;
        ret = maxSumSubArrayContiguous(numbers);
        cout << ret[0] << " " << ret[1] << endl;
    }

    return 0;
}