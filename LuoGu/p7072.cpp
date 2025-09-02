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

int n, w, b[609];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int sc;
        cin >> sc;
        b[sc]++;
        int c = max(1, i * w / 100);
        for (int j = 600; j >= 0; j--) {
            c -= b[j];
            if (c <= 0) {
                cout << j << " ";
                break;
            }
        }
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}