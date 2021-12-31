#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

//Recursive function for Reversing array
int reverseArray(int a[], int size){
    if (size <= 1){
        return 0;
    }
    else {
        int temp;
        int i = 0;
        temp = a[i];

        swap(a[0], a[size-1]);

        reverseArray(&a[1], size-2);
    }
}


int main() {

    int n;
    cout << "Enter number of items in array to be reversed: ";
    cin >> n;
    cout << endl;

    int a[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter value in place " << i << endl;
        cin >> a[i];
    }

    reverseArray(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }


}

/*int reversDigits(int num) {
    int revNum = 0;

    while (num > 0) {
        revNum = revNum * 10 + num % 10;
        num = num / 10;
    }
    return revNum;
}


int main() {

    int num = 0;
    cout << "Input number to be reversed: " << endl;
    cin >> num;

    cout << "Reverse of number is: " << reversDigits(num);
    return 0;
}
*/