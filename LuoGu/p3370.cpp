#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

namespace Hyx {

#ifndef ONLINE_JUDGE
#include "debug_template.hpp"
#else
#define debug(...)
#define debugArr(...) 
#endif // ONLINE_JUDGE

int n;
const int MAXN = 20000;
pair<ull, ull> hashes[MAXN];

// const ull base1 = 233ll, mod1 = 1000001011ll, base2 = 353ll;
const ull prime1[] = {101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499};
const ull prime2[] = {1000000007,1000000009,1000000021,1000000033,1000000087,1000000093,1000000097,1000000103,1000000123,1000000181,1000000207,1000000223,1000000241,1000000271,1000000289,1000000297,1000000321,1000000349,1000000363,1000000403,1000000409,1000000411,1000000427,1000000433,1000000439,1000000447,1000000453,1000000459,1000000483,1000000513,1000000531,1000000579,1000000607,1000000613,1000000637,1000000663,1000000711,1000000753,1000000787,1000000801,1000000829,1000000861,1000000871,1000000891,1000000901,1000000919,1000000931,1000000933,1000000993,1000001011,1000001021,1000001053,1000001087,1000001099,1000001137,1000001161,1000001203,1000001213,1000001237,1000001263,1000001269,1000001273,1000001279,1000001311,1000001329,1000001333,1000001351,1000001371,1000001393,1000001413};
ull base1, mod1, base2;

ull hash1(const string &s) {
    ull ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = (base1 * ans + s[i]) % mod1;
    }
    return ans;
}

ull hash2(const string &s) {
    ull ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = base2 * ans + s[i];
    }
    return ans;
}

bool operator<(const pair<ull, ull> &a, const pair<ull, ull> &b) {
    return a.first < b.first or a.first == b.first and a.second < b.second;
}

bool operator==(const pair<ull, ull> &a, const pair<ull, ull> &b) {
    return a.first == b.first and a.second == b.second;
}

void prep_hash() {
    random_device rd;
    mt19937_64 rng(rd());
    uniform_int_distribution<ull> dist(0, 69);
    
    base1 = prime1[dist(rd)];
    mod1 = prime2[dist(rd)];
    base2 = prime1[dist(rd)];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    prep_hash();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        hashes[i] = {hash1(s), hash2(s)};
    }
    sort(hashes + 1, hashes + n + 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (hashes[i] != hashes[i + 1]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}