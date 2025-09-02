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

// 所有元素相对原子质量扩大两倍，方便处理.5的情况
string s;
const map<string, int> MASS = {
  {"H", 2}, {"C", 24}, {"N", 28}, {"O", 32}, {"F", 38}, {"Na", 46}, {"Mg", 48}, {"Al", 54}, {"Si", 56},
  {"P", 62}, {"S", 64}, {"Cl", 71}, {"K", 78}, {"Ca", 80}, {"Mn", 110}, {"Fe", 112}, {"Cu", 128}, {"Zn", 130}, {"Ag", 216},
  {"I", 254}, {"Ba", 274}, {"Hf", 357}, {"Pt", 390}, {"Au", 394}, {"Hg", 402}
};

inline bool is_element(string x) {
  return MASS.contains(x);
}

int proc_count(const string &s, int st, int *ed) {
  int cnt = 0, i;
  for (i = st+2; isdigit(s[i]); i++) {
    cnt = 10*cnt+s[i]-'0';
  }
  *ed = i+1;
  return cnt;
}

int proc_element(const string &s, int st, int *ed) {
  int i;
  string ele, tmp;
  // 党校一种元素符号是另一种元素符号的前缀的情况！
  for (i = st; i < st+2; i++) {
    tmp += s[i];
    if (is_element(tmp)) {
      ele = tmp;
      *ed = i+1;
    }
  }
  debug(ele);
  return MASS.at(ele);
}

int proc_atom_group(const string &s, int st, int *ed) {
  int i, nxt, partial_mass = 0, mass = 0, cnt = 1;
  for (i = st+1; s[i] != ')'; i = nxt) {
    if (isalpha(s[i])) {
      mass += partial_mass*cnt; cnt = 1;
      partial_mass = proc_element(s, i, &nxt);
    } else if (s[i] == '_') {
      cnt = proc_count(s, i, &nxt);
    }
    debug(nxt);
  }
  mass += partial_mass*cnt;
  *ed = i+1;
  return mass;
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("input.txt", "rb", stdin);
  // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
  cin >> s;
  int ans = 0;
  string s1;
  int i;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == '~') break;
  }
  s1 = s.substr(0, i);
  // 水合物
  if (i != s.size()) {
    string s2;
    s2 = s.substr(i+1, s.size()-i-1);
    if (s2 == "H_{2}O") {
      ans += 36;
    } else {
      int h2o_cnt = 0;
      for (int j = i+1; isdigit(s[j]); j++) {
        h2o_cnt = 10*h2o_cnt+s[j]-'0';
      }
      ans += h2o_cnt*36;
    }
  }
  // 分子
  s1 += "#";
  debug(s1);
  int nxt, cnt = 1, partial_mass = 0;
  for (int i = 0; i < s1.size(); i = nxt) {
    if (isalpha(s1[i])) {
      ans += partial_mass*cnt; cnt = 1;
      partial_mass = proc_element(s1, i, &nxt);
    } else if (s1[i] == '(') {
      ans += partial_mass*cnt; cnt = 1;
      partial_mass = proc_atom_group(s1, i, &nxt);
    } else if (s1[i] == '_') {
      cnt = proc_count(s1, i, &nxt);
    } else if (s1[i] == '#') {
      ans += partial_mass*cnt;
      break;
    }
  }
  cout << ans / 2 << (ans % 2 == 1 ? ".5" : "");
  return 0;
}

}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  return Hyx::main();
}