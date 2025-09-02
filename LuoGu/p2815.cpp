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

string v6, v6_, v6list[8], v6list_[8];

int main() {
#ifndef ONLINE_JUDGE
  // freopen("input.txt", "rb", stdin);
  // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
  cin >> v6;
  for (int i = 0; i*5 < v6.size(); i++) {
    v6list[i] = v6.substr(i*5, min(4, (int)v6.size() - i*5));
    string tmp;
    for (int j = 0; j < v6list[i].size(); j++) {
      if (v6list[i][j] != '0') {
        tmp += v6list[i].substr(j, v6list[i].size()-j);
        break;
      }
    }
    if (tmp != "") {
      v6list[i] = tmp;
    } else {
      v6list[i] = "0";
    }
  }
  debugArr(v6list, 8);
  bool flag = false;
  int omit1 = -1, omit2 = -1, omitlen = 0, mxomitlen = 0;
  for (int i = 0; i < 8; i++) {
    if (v6list[i] == "0") {
      omitlen++;
    } else {
      if (omitlen > mxomitlen) {
        mxomitlen = omitlen;
        omit2 = i-1;
      }
      omitlen = 0;
    }
  }
  if (omitlen > mxomitlen) {
    mxomitlen = omitlen;
    omit2 = 7;
  }
  omitlen = 0;
  omit1 = omit2-mxomitlen+1;
  debug(omit1, omit2);
  if (mxomitlen == 0) {
    for (int i = 0; i < 8; i++) {
      cout << v6list[i] << (i == 7 ? "" : ":");
    }
    cout << "\n";
  } else {
    for (int i = 0; i < omit1; i++) {
      cout << v6list[i] << (i == omit1-1 ? "" : ":");
    }
    cout << "::";
    for (int i = omit2 + 1; i < 8; i++) {
      cout << v6list[i] << (i == 7 ? "" : ":");
    }
    cout << "\n";
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