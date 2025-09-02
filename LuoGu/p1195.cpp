#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#define fprintf if (false) fprintf
#endif 
using ll = long long;
#define forall(x) x.begin(), x.end()

const int N = 1e3 + 5, M = 1e4 + 5;
int n, m, k;
struct Edge {
    int u, v, w;
    friend bool operator<(const Edge& a, const Edge& b) {
        return a.w < b.w;
    }
};
vector<Edge> E;

struct DSU {
    int fa[N];
    
    DSU() {
        for (int i = 0; i < N; i++) {
            fa[i] = i;
        }
    }

    int find(int x) {
        if (fa[x] != x) {
            return fa[x] = find(fa[x]);
        } else {
            return x;
        }
    }

    void link(int x, int y) {
        int fax = find(x), fay = find(y);
        if (fax != fay) {
            fa[fax] = fay;
        }
    }
} dsu;

int cnt = n;
ll ans = 0;

void kruskal() {
    cnt = n;
    sort(forall(E));
    for (auto e : E) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.link(e.u, e.v);
            ans += e.w;
            cnt--;
        }
        if (cnt == k) {
            return;
        }
    }
}

int main() {
    cout.tie(0), cin.tie(0), ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y, l;
        cin >> x >> y >>l;
        E.push_back({x, y, l});
    }
    if (k > n) {
        cout << "No Answer";
        return 0;
    }
    if (k == n) {
        cout << 0;
        return 0;
    }
    kruskal();
    if (cnt > k) {
        cout << "No Answer";
    } else {
        cout << ans;
    }
    return 0;
}