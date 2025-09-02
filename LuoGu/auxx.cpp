#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned ll;

namespace Hyx {

#ifndef ONLINE_JUDGE
#include "debug_template.hpp"
#else
#define debug(...)
#define debugArr(...) 
#endif // ONLINE_JUDGE

bool is_pri(ull x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cout << "const ull prime1[] = {";

        int cnt = 0;


    for (ull i = 100; cnt < 70; i++) {
        if (is_pri(i)) {
            cout << i << "ull,";
            cnt++;
        }
    }
    cout << "};\n";

    cout << "const ull prime2[] = {";
    cnt = 0;
    for (ull i = 1e9 + 1; cnt < 70; i += 2) {
        if (is_pri(i)) {
            cnt++;
            cout << i << "ull,";
        }
    }
    cout << ");\n";
    map<int, int>mp = {{1,2}};
    cout << mp.at(4234);
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}