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

int n, m;
int buck[10'0005];
vector<int> s[5'0005];

void solve() {
  fill(buck, buck+m+1, 0);
  for (int i = 0; i < n+1; i++) s[i].clear();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int l;
    cin >> l;
    for (int j = 1; j <= l; j++) {
      int v;
      cin >> v;
      s[i].emplace_back(v);
      buck[v]++;
    }
  }

  int method_cnt = 0;

  // 选 n 个集合
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    cnt += buck[i] > 0;
  }
  debug(cnt, m);
  if (cnt < m) {
    cout << "NO\n";
    return;
  }
  method_cnt = 1;

  // 选 n-1 个集合, 不选 1 个集合
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j : s[i]) {
      if (buck[j] <= 1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      method_cnt++;
    }
  }
  debugArr(buck, m+1);
  debug(method_cnt);
  if (method_cnt >= 3) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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