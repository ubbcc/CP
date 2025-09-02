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
    int q;
    cin >> q;
    ll delta = 0, fr = 0, tot_len = 0;
    vector<ll> qu, qu_l;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            ll l;
            cin >> l;
            qu.emplace_back(tot_len);
            qu_l.emplace_back(l);
            tot_len += l;
        } else if (op == 2) {
            delta += qu_l[fr];
            fr += 1;
        } else {
            int k;
            cin >> k;
            // cout << qu[k + fr - 1] - qu[fr] - qu_l[fr] << "\n";
            cout << qu[k + fr - 1] - delta << "\n";
        }
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}