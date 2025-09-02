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

const int MAXN = 5e3, INF = 1e9;
int mp[MAXN][MAXN], n;
int dis[MAXN * MAXN];

int enc(int x, int y) {
    return x * (n + 2) + y;
}

int enc(pair<int, int> p) {
    return enc(p.first, p.second);
}

struct Node {
    pair<int, int> u; int dis;
    friend bool operator<(const Node &a, const Node &b) {
        return a.dis > b.dis;
    }
};
priority_queue<Node> pq;
bitset<MAXN * MAXN> vis;

const int dx[] = {1,  1,  0, -1, -1, -1, 0, 1};
const int dy[] = {0, -1, -1, -1,  0,  1, 1, 1};
 
void dijkstra(pair<int, int> s) {
    dis[enc(s)] = 0;
    pq.emplace(Node{s, 0});
    while (pq.size()) {
        Node node = pq.top(); pq.pop();
        auto u = node.u;
        if (vis[enc(u)]) continue;
        vis[enc(u)]  = true;
        int x = u.first, y = u.second;
        debug(u);
        for (int o = 0; o < 8; o++) {
            int x_ = x + dx[o], y_ = y + dy[o];
            if (x_ >= 0 and x_ <= n + 1 and  y_ >= 0 and y_ <= n + 1 and mp[x_][y_] == 0) {
                if (dis[enc(x_, y_)] > dis[enc(x, y)] + 1) {
                    dis[enc(x_, y_)] = dis[enc(x, y)] + 1;
                    pq.emplace(Node{{x_, y_}, dis[enc(x_, y_)]});
                }
            }
            debug(x_, y_, dis[enc(x_, y_)]);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    fill((int*)dis, (int*)dis + (n + 2) * (n + 2), INF);
    dijkstra({1, 1});
    if (dis[enc(n, n)] == INF) {
        cout << "-1";
    } else {
        cout << dis[enc(n, n)];
    }
#ifndef ONLINE_JUDGE
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j ++) {
            cout << dis[enc(i, j)]<< " ";
        }
        cout << "\n";
    }
#endif
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}