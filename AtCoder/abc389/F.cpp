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

const int N = 2e5 + 10;
int l[N], r[N], n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    debug(n);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    int q;
    cin >> q;
    debug(q);
    while (q--) {
        int x;
        cin >> x;
        for (int i = 1; i <= n; i++) {
            if (l[i] <= x and x <= r[i]) {
                x++;
            }
        }
        cout << x << "\n";
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}