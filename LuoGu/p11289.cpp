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

int n, m; const int N = 20'0005;
struct Jobs {
  int s, t;
  bool operator<(const Jobs &oth) const {
    return s < oth.s;
  }
} jobs[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rb", stdin);
  // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> jobs[i].s >> jobs[i].t;
  }
  sort(&jobs[1], &jobs[n+1]);
  
  return 0;
}

}

int main() {
#ifndef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE
  return Hyx::main();
}