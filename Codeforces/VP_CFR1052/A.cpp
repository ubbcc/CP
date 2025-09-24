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

int cnt[105], n;

void solve() {
  fill(cnt, cnt+105, 0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    cnt[v]++;
  }
  int mx = -1;
  for (int tot = 1; tot <= n; tot++) {
    int c = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] >= tot) {
        c++;
      }
    }
    mx = max(mx, c*tot);
  }
  cout << mx << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rb", stdin);
  // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
  int t;
  for (cin >> t; t > 0; t--) {
    solve();
  }
  return 0;
}

}

int main() {
#ifndef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE
  return Hyx::main();
}