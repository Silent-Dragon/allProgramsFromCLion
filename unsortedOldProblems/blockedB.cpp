#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

struct billboard {
    int x1, y1, x2, y2;
};

billboard a, b, t;

int area (billboard r) {

    return (r.x2 - r.x1) * (r.y2 - r.y1);

    //or could i just use the abs value of r[0] - r[1]?
}

int intersect_area (billboard p, billboard q) {
    int x_overlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
    int y_overlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
    return x_overlap * y_overlap;
}

int main() {
     freopen ("billboard.in", "r", stdin);
     freopen ("billboard.out", "w", stdout);


    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;

    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    // cout << area(a) << " " << area(b);
    cout << area(a) + area(b) - intersect_area(a, t) - intersect_area(b, t) << "\n";

    return 0;
}