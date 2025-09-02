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

int a[45][45], n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    int cnt = 1, x = 1, y = (n + 1) / 2;
    a[x][y] = cnt;
    cnt++;
    for (; cnt <= n * n; cnt++) {
        if (x == 1 and y <= n - 1) {
            a[n][y + 1] = cnt;
            x = n, y = y + 1;
        } else if (x >= 2 and y == n) {
            a[x - 1][1] = cnt;
            x = x - 1, y = 1;
        } else if (x == 1 and y == n) {
            a[x + 1][y] = cnt;
            x = x + 1;
        } else {
            if (a[x - 1][y + 1] == 0) {
                a[x - 1][y + 1] = cnt;
                x = x - 1, y = y + 1;
            } else {
                a[x + 1][y] = cnt;
                x = x + 1;
            }
        }
        
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}