#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
stack<int> st;
string s;
int res, tmp = 1, val = 0;

void input () {
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == '(') {
            st.pop();
            st.push(s[i-1]-'0');
            st.push(-1);
        }
        else if (ch == ')') {
            val = 0;
            while(st.top() != -1) {
                val += st.top(); st.pop();
            }
            st.pop(); // ( pop
            val *= st.top(); st.pop();
            st.push(val);
        }
        else {
            st.push(1);
        }
    }

    while (!st.empty()) {
        res += st.top(); st.pop();
    }
    cout << res << endl;
}

int main() {
    fastio;
    input();
}