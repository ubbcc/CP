#include <bits/stdc++.h>
using namespace std;

int n, m, p;
const int MAXN = 5005;

// 并查集部分

int fa[MAXN], rnk[MAXN];
void initSet() {
    for (int i = 0; i < MAXN; i++) {
        fa[i] = i;
        rnk[i] = 0;
    }
}

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]); // 子问题缩小
    }
    return fa[x];
}

void link(int x, int y) {
    int fax = find(x), fay = find(y);
    if (fax != fay) {
        if (rnk[fax] > rnk[fay]) {
            fa[fay] = fax;
        } else {
            fa[fax] = fay;
            rnk[fay]++;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("p1551.in", "rb", stdin);
    freopen("p1551.out","wb", stdout);
#endif // ONLINE_JUDGE
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> p;
    initSet();
    for (int i = 0; i < m; i++) {
        int m1, m2; cin >> m1 >> m2;
        link(m1, m2);
    }
    for (int i = 0; i < p; i++) {
        int p1, p2; cin >> p1 >> p2;
        int fa1 = find(p1), fa2 = find(p2);
        if (fa1 == fa2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}