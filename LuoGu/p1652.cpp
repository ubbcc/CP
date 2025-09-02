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

int n, x1, x2, y1, y2;
struct Circ { int x, y, r; } circ[100];

inline int dist2(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); 
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> circ[i].x;
    }
    for (int i = 1; i <= n; i++) {
        cin >> circ[i].y;
    }
    for (int i = 1; i <= n; i++) {
        cin >> circ[i].r;
    }
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((dist2(circ[i].x, circ[i].y, x1, y1) <= circ[i].r * circ[i].r and dist2(circ[i].x, circ[i].y, x2, y2) > circ[i].r * circ[i].r)
            or (dist2(circ[i].x, circ[i].y, x2, y2) <= circ[i].r * circ[i].r and dist2(circ[i].x, circ[i].y, x1, y1) > circ[i].r * circ[i].r)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}