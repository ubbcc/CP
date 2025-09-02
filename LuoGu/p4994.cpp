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

const int N = 1e7;
int f[N], m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> m;
    f[0] = 0, f[1] = 1;
    for (int i = 2; i < N; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % m;
    }
    int i = 1;
    while (i < N - 1 and (f[i] != 0 or f[i + 1] != 1)) {
        i++;
    }
    cout << i;
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}