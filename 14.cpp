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

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    double a[100], b[100];
    cout.precision(10);
    a[1] = 1.0, b[1] = 1.0;
    for (int i = 1; i <= 50; i++) {
        a[i + 1] = a[i] + 1.0 / b[i], b[i + 1] = b[i] + 1.0 / a[i];
        cout << i << " " << a[i] << " " << b[i] << " " << a[i] / b[i] << " " << a[i] * b[i] << "\n";
    }
    cout << a[50] << " " << b[50];
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}