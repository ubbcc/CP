#include <bits/stdc++.h>
using namespace std;

bool chk() {
    ifstream inf("p1241.out", ios::in | ios::binary);
    string s; inf >> s;
    stack<char> st;
    for (char i : s) {
        if (i == '(' || i == '[') {
            st.push(i);
        } else {
            if (st.empty()) {
                return false;
            } else {
                if (i == ')' && st.top() == '(' || i == ']' && st.top() == '[') {
                    st.pop();
                }
            }
        }
    }
    if (st.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t = 1000;
    freopen("p1241.log", "wb", stdout);
    while (t--) {
        int res;
        system("p1241gen.exe");
        system("p1241.exe");
        if (chk()) {
            cout << "AC" << endl;
        } else {
            cout << "WA" << endl;
            break;
        }
    }
    return 0;
}