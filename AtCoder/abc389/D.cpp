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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    double r;
    cin >> r;
    ll ans = 0;
    const double sqrt2 = numbers::sqrt2;
    for (ll i = -r; i <= r; i++) {
        double ds1 = r * r - (-i - 0.5) * (-i - 0.5);
        double ds2 = r * r - (-i + 0.5) * (-i + 0.5);
        if (ds1 >= 1e-9 and ds2 >= 1e-9) {
            debug(i, ds1, ds2);
            ans += 2 * min((ll)floor(sqrt(ds1) - 0.5), (ll)floor(sqrt(ds2) - 0.5)) + 1;
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