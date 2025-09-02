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

int n;
double d;
struct Interval { double l, r; };
vector <Interval> intv;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> d;
    for (int i = 1; i <= n; i++ ) {
        double px, py;
        cin >> px >> py;
        if (py > d) {
            cout << "-1";
            return 0;
        }
        double dx = sqrt(d * d - py * py);
        intv.emplace_back(Interval{px - dx, px + dx});
    }
    sort(intv.begin(), intv.end(), [](Interval a, Interval b) { return a.r < b.r; });
    int ans = 0, last = 0;
    for (int i = 0; i < n; i++ ) {
        if (i == 0 or intv[last].r < intv[i].l) {
            ans++;
            last = i;
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