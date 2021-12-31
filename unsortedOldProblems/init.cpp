#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int a[5];
int a2d[5][5];
vector <int> v;
map <int, string> m;
string s = " ";
int n = 0;
char ch = ' ';
double d = 0;
long int ln = 0;
long long int lln = 0;
bool boo = false;

int main() {
    memset(a, 0, sizeof(a));
    memset(a2d, 0, sizeof(a2d));
    for (unsigned int i = 0; i < v.size(); i++) {
        v[i] = 0;
    }
    for (int i = 0; i < m.size(); i++) {
        m[i] = " ";
    }

    return 0;
}