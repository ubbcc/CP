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

vector<string> text, input;
int t, cnt;

// 确实，一直wa最后五个点，原来是范文也能退格，离谱

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    // freopen("output.txt", "wb", stdout);
#endif // ONLINE_JUDGE
    // text.emplace_back(string(" ")), input.emplace_back(string(" "));
    string tmp;
    while (getline(cin, tmp), tmp != "EOF") {
        text.emplace_back(tmp);
    }
    while (getline(cin, tmp), tmp != "EOF") {
        input.emplace_back(tmp);
    }
    cin >> t;
    for (int i = 0; i < text.size() and i < input.size(); i++) {
        string correct_input = "", x = input[i];
        string correct_text = "";
        for (int j = 0; j < x.length(); j++) {
            if (x[j] == '<' and correct_input.size() > 0) {
                correct_input.pop_back();
            } else if (x[j] != '<') {
                correct_input.push_back(x[j]);
            }
        }
        input[i] = correct_input;
        x = text[i];
        for (int j = 0; j < x.length(); j++) {
            if (x[j] == '<' and correct_text.size() > 0) {
                correct_text.pop_back();
            } else if (x[j] != '<') {
                correct_text.push_back(x[j]);
            }
        }
        text[i] = correct_text;
        debug(i, correct_text, correct_input);
        for (int j = 0; j < input[i].length() and j < text[i].length(); j++) {
            // debug(i, j, correct_input[j], text[i][j]);
            if (input[i][j] == text[i][j]) {
                cnt++;
            }
        }
    }
    cout << (int)round(cnt / (t / 60.0)) << "\n";
    // cout<<(int)(cnt*60.0/t+0.5)<<endl;
    return 0;
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Hyx::main();
}