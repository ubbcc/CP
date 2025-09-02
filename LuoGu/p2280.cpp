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

int mp[5005][5005], sum_mp[5005][5005];
int n, m;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rb", stdin);
  // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    mp[x+1][y+1] = v;
  }
  for (int i = 1; i <= 5000; i++) {
    for (int j = 1; j <= 5000; j++) {
      sum_mp[i][j] = sum_mp[i-1][j-1]-sum_mp[i][j-1]-sum_mp[i-1][j]+mp[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i+m <= 5001; i++) {
    for (int j = 1; j+m <= 5001; j++) {
      ans = max(ans, sum_mp[i][j]-sum_mp[i+m-1][j]-sum_mp[i][j+m-1]+sum_mp[i+m-1][j+m-1]);
    }
  }
  cout << ans;
  return 0;
}

}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  return Hyx::main();
}