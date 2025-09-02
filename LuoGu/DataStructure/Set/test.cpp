#include <bits/stdc++.h>
using namespace std;

namespace Rnd {
    random_device rd;
    mt19937 rng(rd());

    inline int randInt(int a, int b) {
        uniform_int_distribution<> d(a, b);
        return d(rng);
    }
}

void gen() {
    ofstream fout("t.in", ios::out | ios::binary);
    const int N = 50, M = 100;
    typedef pair<int, int> pii;
    vector<pii> edges;
    fout << N << ' ' << M << " \n";
    for (int i = 1; i <= M; i++) {
        int u = Rnd::randInt(1, N);
        int v = Rnd::randInt(1, N);
        while (v == u) {
            v = Rnd::randInt(1, N);
        }
        //edges.push_back({u, v});
        fout << u << ' ' << v << " \n";
    }
    fout.close();
}


int main() {
    const int N = 100;
    system("g++ 1.cpp -O2 -o 1.exe");
    system("g++ 12.cpp -O2 -o 12.exe");
    for (int i = 1; i <= N; i++) {
        gen();
        system("1.exe < t.in > t1.ans");
        system("12.exe < t.in > t2.out");
        if (system("fc t1.ans t2.out")) {
            cout << "[" << i << "] UNAC " << endl;
            break;
        } else {
            cout << "[" << i << "] AC " << endl;
        }
    }
    return 0;
}