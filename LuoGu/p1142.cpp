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

using Point = complex<ll>;
using Vec = Point;
Point pt[800];
int n;

inline ll dir(Point p, Point q1, Point q2) {
    Vec r1 = q1 - p, r2 = q2 - p;
    return (r1 * conj(r2)).imag();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        pt[i].real(x), pt[i].imag(y);
    }
    int mx = -1, cnt;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cnt = 2;
            for (int k = 1; k <= n; k++) {
                if (k != i and k != j and dir(pt[i], pt[j], pt[k]) == 0) {
                    cnt++;
                } 
            }
            mx = max(mx, cnt);
        }
    }
    cout << mx;
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}