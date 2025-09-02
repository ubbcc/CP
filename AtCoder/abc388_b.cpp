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

const int N = 106;
int t[N], l[N], l1[N], n, d;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> l[i];
    }
    for (int k = 1; k <= d; k++) {
        int mx = -1;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, t[i] * (l[i] + k));
        }
        cout << mx << "\n";
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}