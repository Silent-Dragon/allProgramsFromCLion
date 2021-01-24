#include <iostream>
#include <deque>

using namespace std;

deque <int> deq;
int n;

int main() {
    ///input
    cout << "Please enter number of items you want in your deque";
    cin >> n;

    int input[n];
    for (int i = 0; i < n; i++) {
        cout << "Please enter a value for your deque at place " << i + 1 << " ";
        cin >> input[i];

        deq.push_front(input[i]); //add to front of deque
        //deq.push_back(input[i]) //add to back of deque
        //deq.insert(input[i]) //add to deque
    }

    ///printing deque
    for (auto itr = deq.begin(); itr != deq.end(); itr++) {
        cout << *itr << " ";
    }

    cout << "First element of deque is " << deq.front() << endl;
    cout << "Last element of deque is " << deq.back() << endl;

    ///size of deque
    cout << "Size of deque is " << deq.size() << endl;
    cout << "Max size that deque can have is " << deq.max_size()  << endl;

    ///removal


  /*

     cout << "\ngquiz.at(2) : " << gquiz.at(2);
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();

    cout << "\ngquiz.pop_front() : ";
    gquiz.pop_front();
    showdq(gquiz);

    cout << "\ngquiz.pop_back() : ";
    gquiz.pop_back();
    showdq(gquiz);
*/
    return 0;
}
