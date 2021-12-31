#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cout << "Enter number of values in both 1d arrays" << endl;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter value for array in place " << i + 1 << endl;
        cin >> array[i];
    }

    int array2[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter value for array 2 in place " << i + 1 << endl;
        cin >> array2[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "Min value from both arrays in place " << i + 1 << endl;
        cout << min(array[i], array2[i]);
        cout << endl;
    }

    int m;
    cout << "Enter number of values in both 2d arrays" << endl;
    cin >> m;

    int array3[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter value for array 3 in place " << i + 1 << ", " << j + 1 << endl;
            cin >> array3[i][j];
        }
    }

    int array4[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter value for array 4 in place " << i + 1 << ", " << j + 1 << endl;
            cin >> array4[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Min value from both arrays in place " << i + 1 << ", " << j + 1 << endl;
            cout << min(array3[i][j], array4[i][j]);
            cout << endl;
        }
    }


    return 0;
}
