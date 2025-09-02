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

const int MAXN= 1e6;
struct Edge {
    int v, w, nxt;
} E[MAXN];
int n, m, s, ecnt = 0;
int dis[MAXN], head[MAXN];

void addE(int u, int v, int w) {
    E[++ecnt] = {v, w, head[u]};
    head[u] = ecnt;
}

struct Info {
    int node, val;
    friend bool operator<(const Info &a, const Info &b) {
        return a.val > b.val;
    }
};

priority_queue<Info> pq;
bitset <MAXN> vis;

void dijkstra(int s) {
    dis[s] = 0;
    pq.emplace((Info){s, dis[s]});
    while (pq.size()) {
        int u = pq.top().node;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i; i = E[i].nxt) {
            int v = E[i].v, w = E[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    pq.emplace((Info){v, dis[v]});
                }
            } 
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> m >> s;
    debug(n, m, s);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addE(u, v, w);
    }
    fill(dis, dis + n + 1, 1e9 + 10);
    dijkstra(s);
    for (int i = 1; i <= n; i ++) {
        cout << dis[i] << ' ';
    }
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}