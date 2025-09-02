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

const int MAXN = 2e3+5;
int n, v[MAXN], f[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    for (int i = 1; i <= n; i ++) {
      cin >> v[i];
    }

    for (int l = 1; l <= n; l++) {
      for (int i = 0; i <= l; i++) {
        if (i >= 1) {
          f[l][i] = max(f[l][i], f[l-1][i-1]+v[i]*l);
        }
        if (i < l) {
          f[l][i] = max(f[l][i], f[l-1][i]+v[n-(l-i)+1]*l);
        }
      }
#ifndef ONLINE_JUDGE
      int ans = -1;
      for (int i = 0; i <= l; i++) {
        ans = max(ans, f[l][i]);
      }
      debug(l, ans);
#endif 
    }
    int ans = -1;
    for (int i = 0; i <= n; i++) {
      ans = max(ans, f[n][i]);
    }
    cout << ans;
    return 0;
}

}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  return Hyx::main();
}