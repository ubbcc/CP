#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace Hyx {

#ifndef ONLINE_JUDGE
#include "../debug_template.hpp"
#else
#define debug(...)
#define debugArr(...) 
#endif // ONLINE_JUDGE

const int MAXN = 1e4;
int n, x[MAXN*2];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rb", stdin);
  // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
  cin >> n;
  for (int i = 1; i <= 2*n; i++) {
    cin >> x[i];
  }
  int ans = 0;
  for (int k = 1; k <= n; k++) {
    int pos[2], cnt = 0;
    for (int j = 1; j <= 2*n; j++) {
      if (x[j] == k) {
        pos[cnt++] = j;
      }
    }
    ans = max(ans, pos[1]-pos[0]-1);
  }
  cout << ans;
  return 0;
}

}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  return Hyx::main();
}