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

__int128 x,y,z;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    int t;
    for (cin >> t; t; t--) {
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        __int128 lcm1 = (__int128)a*b/__gcd(a,b);
        __int128 lcm2 = (__int128)a*c/__gcd(a,c);
        __int128 lcm3 = (__int128)lcm1*c/__gcd(lcm1,(__int128)c);
        cout << (ll)(n/a-n/lcm1+n/c-(n/lcm2-n/lcm3)) << "\n";
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}