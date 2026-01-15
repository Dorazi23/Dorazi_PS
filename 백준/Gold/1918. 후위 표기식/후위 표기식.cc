#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
string s, res;
stack<char> st;

int operation (char ch) {
    if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return 0;
}

void input () {
    cin >> s;
    for (auto ch : s) {
        if (isalnum(ch)) res += ch;
        else if (ch == '(') st.push(ch);
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top(); st.pop();
            }
            st.pop();
        }
        else { // 연산자 
            while (!st.empty() && operation(st.top()) >= operation(ch)) {
                if (st.top() == '(') break;
                res += st.top(); st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        char tmp = st.top(); st.pop();
        res += tmp;
    }

    cout << res << endl;
}

int main() {
    fastio;
    input();
}