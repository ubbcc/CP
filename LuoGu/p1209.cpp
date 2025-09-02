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

const int MAXN = 500;
int m, s, c, icnt;
vector <int> p(MAXN), intervals;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
  cin >> m >> s >> c;
  for (int i = 0; i < c; i++) {
    cin >> p[i];
  }
  sort(&p[0], &p[c]);
  for (int i = 0; i < c-1; i++) {
    intervals.emplace_back(p[i+1]-p[i]-1);
    icnt++;
  }
  sort(intervals.begin(), intervals.end());
  if (c <= m) {
    cout << c;
  } else {
    int m1 = c;
    int ans = c;
    for (int i = 0; i < icnt and m1 > m; i++) {
      ans += intervals[i];
      m1--;
    }
    cout << ans;
  }
  return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}