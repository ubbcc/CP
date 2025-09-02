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
    int l = 1, r = 1e9, mid;
    while (l <= r) {
        int mid = (l + r) / 2;
        cout << mid << endl;
        int res;
        cin >> res;
        if (res == 0) {
            return 0;
        } else if (res == 1) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}