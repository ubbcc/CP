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

const int N = 3e6 + 10;
int n, k, nxt[N], nxt_[N], ans[N];
ll m, p[N]; // p <= 1e18

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> k >> m;
    // fill(p + 1, p + n + k + 100, (ll)3e18);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int h = 1, t = k + 1; // 不算本点
    for (int i = 1; i <= n; i++) {
        while (t + 1 <= n and p[t + 1] - p[i] < p[i] - p[h]) {
            t++; h++;
        }
        if (p[t] - p[i] > p[i] - p[h]) {
            nxt[i] = t;
        } else {
            nxt[i] = h;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }
    for (ll x = m; x; x >>= 1) {
        if (x & 1) {
            for (int i = 1; i <= n; i++) {
                ans[i] = nxt[ans[i]];
            }
        }
        copy(nxt + 1, nxt + n + 1, nxt_ + 1);
        // debugArr(nxt, n + 1, nxt_, n + 1);
        for (int i = 1; i <= n; i++) {
            nxt[i] = nxt_[nxt_[i]];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}