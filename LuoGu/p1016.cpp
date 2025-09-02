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

int n;
double d1, d2, c;
struct Sta {
  double p, d;
  bool operator<(const Sta &oth) { return d < oth.d; }
} sta[10];
void print(Sta x) {
  cerr << "PRICE " << x.p << " DISTANCE " << x.d;
}
const double EPS = 1e-3;

double ans = 1e10;

void dfs(int s, double price) {
  if (s == n+1) {
    ans = min(ans, price);
    return;
  }
  for (int i = s+1; i <= n+1; i++) {
    if (sta[i].d-sta[s].d > c+EPS) break;
    dfs(i, price+(sta[i].d-sta[s].d)*sta[s].p);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rb", stdin);
  // freopen("output.txt", "wb", stdout);
#endif
  cin >> d1 >> c >> d2 >> sta[0].p >> n;
  for (int i = 1; i <= n; i++) {
    cin >> sta[i].d >> sta[i].p;
    sta[i].d /= d2;
  }
  sta[n+1].d = d1/d2;
  sort(sta, sta+n+2);
  debugArr(sta, n+2);
  for (int i = 1; i <= n+1; i++) {
    if (sta[i].d-sta[i-1].d > c+EPS) {
      cout << "No Solution";
      return 0;
    }
  }
  dfs(0, 0);
  cout << fixed << setprecision(2) << ans;
  return 0;
}

}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  return Hyx::main();
}