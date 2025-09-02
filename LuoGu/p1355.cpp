#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace Hyx {

#ifndef ONLINE_JUDGE
#include "debug_template.hpp"
#else
#define debug(...)
#define debugArr(...) 
#endif // ONLINE_JUDGE

struct Point {
    int x, y;
    friend bool operator==(const Point& a, const Point& b) { return a.x == b.x and a.y == b.y; }
} p[10];

int dir(Point p1, Point q, Point p2) {
    Point r1 = {p1.x - q.x, p1.y - q.y};
    Point r2 = {p2.x - q.x, p2.y - q.y};
    return r1.x * r2.y - r1.y * r2.x;
}

inline int sgn(int x) {
    if (x > 0) return 1;
    else if (x == 0) return 0;
    else return -1;
}

bool on_seg(Point p1, Point q, Point p2) {
    
    return q == p1 or q == p2 or 
           dir(p1, q, p2) == 0 and 
           min(p1.x, p2.x) <= q.x and q.x <= max(p1.x, p2.x) and 
           min(p1.y, p2.y) <= q.y and q.y <= max(p1.y, p2.y) ;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    char c;
    cin >> c >> p[1].x >> c >> p[1].y >> c;
    cin >> c >> p[2].x >> c >> p[2].y >> c;
    cin >> c >> p[3].x >> c >> p[3].y >> c;
    cin >> c >> p[4].x >> c >> p[4].y >> c;
    Point q = p[4];
    if (q == p[1] or q == p[2] or q == p[3]) {
        cout << 4;
    } else {
        // if (dir(p[1], q, p[2]) == 0 or dir(p[2], q, p[3]) == 0 or dir(p[3], q, p[1]) == 0) {
        if (on_seg(p[1], q, p[2]) or on_seg(p[2], q, p[3]) or on_seg(p[3], q, p[1]) ) {
            cout << 3;
        } else if (sgn(dir(p[1], q, p[2])) + sgn(dir(p[2], q, p[3])) + sgn(dir(p[3], q, p[1])) == -3 or
                  sgn(dir(p[1], q, p[2])) + sgn(dir(p[2], q, p[3])) + sgn(dir(p[3], q, p[1])) == 3) {
            cout << 1;
        } else {
            cout << 2;
        }
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}