#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

double interestPct = 0;
double repaymentPct = 0;
int cnt;
void calculatePayment(double debt, double totalRepaid) {

    if (debt <= 0) {
        //cout << totalRepaid << endl;
        cout << cnt << endl;
        return;
    }


    debt = debt + interestPct * debt;

    // cout << "Debt before repayment: " << debt << endl;

    if (repaymentPct * debt > 50) {
        totalRepaid += repaymentPct * debt;
        debt = debt - repaymentPct * debt;
    } else {
        if (debt - 50 < 0) {
            totalRepaid += debt;
            debt = 0;
        } else {
            totalRepaid += 50;
            debt = debt - 50;
        }
    }


    cnt++;
    // cout << "Debt after repayment: " << debt << " Total after repayment: " << totalRepaid << endl;

    calculatePayment(debt, totalRepaid);
}


int main() {

    cin >> interestPct >> repaymentPct;

    interestPct /= 100;
    repaymentPct /= 100;

    calculatePayment(100, 0);

    return 0;
}