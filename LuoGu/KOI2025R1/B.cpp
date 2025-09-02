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

const int MAXN = 1e5+5;
using pii = pair<int, int>;
int n; pii p[MAXN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rb", stdin);
  // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
  cin >> n;
  int ymn = 1e9, ymx = -1e9;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
    ymn =  min(p[i].second, ymn);
    ymx =  max(p[i].second, ymx);
  }

  int b1 = -1e9, b2 = -1e9;
  for (int i = 1; i <= n; i++) {
    b1 = max(b1, -p[i].first+p[i].second); b2 = max(b2, p[i].first+p[i].second);
  }
  int ans1 = abs(2*ymn-b1-b2);

  b1 = 1e9, b2 = 1e9;
  for (int i = 1; i <= n; i++) {
    b1 = min(b1, -p[i].first+p[i].second); b2 = min(b2, p[i].first+p[i].second);
  }
  int ans2 = abs(2*ymx-b1-b2);

  cout << min(ans1, ans2);

  return 0;
}

}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  return Hyx::main();
}