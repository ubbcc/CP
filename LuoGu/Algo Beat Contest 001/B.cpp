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

int l, r, dig[100];

bool chk(int x) {
    int i = 1; 
    while (x > 0) {
        dig[i] = x % 10;
        x /= 10;
        i++;
    }
    i--;
    if ((i) % 2 == 0) {
        return false;
    }
    return dig[1] == dig[(i + 1) / 2] and dig[1] == dig[i];
}

void sol(void) {
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (chk(i)) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    int t;
    for (cin >> t; t--; ) {
        sol();
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}