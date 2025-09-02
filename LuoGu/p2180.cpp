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

ll n, m, k, ans = 0;

ll get(ll w, ll h) {
    return w * h * (w * h - w - h + 1) / 4;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> m >> k;
    for (ll w = 1; w <= n; w++) {
        ll rem = k % w,  h = k / w + (rem > 0);
        if (h > m or h == 0) {
            continue;
        }
        if (rem > 0) {
            ans = max(ans, get(rem, h) + get(w, h - 1) - get(rem, h - 1));
            debug(w, h, rem, ans);
        } else {
            ans = max(ans, get(w, h));
            debug(w, h, rem, ans);
        }
    }
    // 多余石子可以摆在末行也可以摆在末列
    swap(n, m);
    for (ll w = 1; w <= n; w++) {
        ll rem = k % w,  h = k / w + (rem > 0);
        if (h > m or h == 0) {
            continue;
        }
        if (rem > 0) {
            ans = max(ans, get(rem, h) + get(w, h - 1) - get(rem, h - 1));
            debug(w, h, rem, ans);
        } else {
            ans = max(ans, get(w, h));
            debug(w, h, rem, ans);
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