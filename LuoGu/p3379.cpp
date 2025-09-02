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

const int N = 1e6 + 10;

struct Edge {
    int to, nxt;
} E[N];
int tot_edge = 0, head[N], dep[N], anc[20][N];
int n, m, s;

void add_edge(int u, int v) {
    tot_edge++;
    E[tot_edge] = {v, head[u]};
    head[u] = tot_edge;
}

void dfs(int fa, int u) {
    dep[u] = dep[fa] + 1;
    anc[0][u] = fa;
    for (int i = head[u]; i; i = E[i].nxt) {
        int v = E[i].to;
        if (v == fa) continue;
        dfs(u, v);
    }
}

int lca(int a, int b) {
    if (dep[a] != dep[b]) {
        if (dep[a] > dep[b]) {
            swap(a, b);
        }
        int delta_dep = dep[b] - dep[a];
        for (int i = 19; i >= 0; i--) {
            if (delta_dep & (1 << i)) {
                b = anc[i][b];
            }
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 19; i >= 0; i--) {
        if (anc[i][a] != anc[i][b]) {
            a = anc[i][a], b = anc[i][b];
        }
    } 
    return anc[0][a];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y), add_edge(y, x);
    }
    dfs(0, s);
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= n; j++) {
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }
    for (; m > 0; m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}