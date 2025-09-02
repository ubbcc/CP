#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace Hyx {

#ifndef ONLINE_JUDGE
// #include "debug_template.hpp"
#else
#define debug(...)
#define debugArr(...) 
#endif // ONLINE_JUDGE

int a[100];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    int n = 8;
    for (int i = 1; i <= 2 * n; i++) {
        a[i] = i;
    }
    mt19937 rng(time(0));
    shuffle(a + 1, a + 2 * n + 1, rng);
    auto check = [&n](int a[]) -> bool {
        for (int i = 1; i <= n; i++) {
            if (a[i] - a[i + n] != i) {
                return false;
            }
        }
        return true;
    };
    int cnt = 0;
    do {
        if (check(a)) {
            cout << "a:";
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << "\nb:";
            for (int i = n + 1; i <= 2 * n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n---------\n";
            cnt++;
        }
    } while (next_permutation(a + 1, a + 2 * n + 1));
    cout << "cnt = " << cnt;
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}