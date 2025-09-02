#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 30;
string a[MAXN];
mt19937 rng(time(0));

bool _gt(const string& a, const string& b) // a > b
{
    int minl = min(a.size(), b.size());
    for (int i = 0; i < minl; i++)
    {
        if (a[i] != b[i]) 
            return (a[i] > b[i]);
    }
    if (a.size() < b.size())
    {
        for (int i = minl; i < b.size(); i++)
        {
            if (a[a.size() - 1] != b[i]) 
                return (a[a.size() - 1] > b[i]);
        }
    }
    else
    {
        for (int i = minl; i < a.size(); i++)
        {
            if (b[b.size() - 1] != a[i]) 
                return (a[i] > b[b.size() - 1]);
        }
    }
    return false;
}

void quick_sort(string v[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, ipiv = l + rng() % (r - l + 1); string piv = v[ipiv];
        while (i <= j)
        {
            while (_gt(v[i], piv)) i++;
            while (_gt(piv, v[j])) j--;
            if (i <= j) swap(v[i++], v[j--]);
        }
        quick_sort(v, l, j);
        quick_sort(v, i, r);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("p1012.in", "rb", stdin);
    freopen("p1012.out","wb", stdout);
#endif // ONLINE_JUDGE
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n; for (int i = 0; i < n; i++) cin >> a[i];
    quick_sort(a, 0, n - 1);
    //sort(a, a + n, [](const string& a, const string& b)->bool { return (a > b); });
    for(auto i : a) cout << i;

    return 0;
}