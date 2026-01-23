#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
string s;
stack<char> st;
int answer;

void input () {
    cin >> s;
    for (auto ch : s) {
        if (ch == '(' || ch == '[') st.push(ch);
        else if (ch == ')') {
            if (st.empty() || st.top() != '(') {
                cout << "0" << endl;
                return;
            }
            st.pop();
        }
        else { // ]
            if (st.empty() || st.top() != '[') {
                cout << "0" << endl;
                return;
            }
            st.pop();
        }
    }
    if (!st.empty()) {
        cout << "0" << endl;
        return;
    }
    
    // 괄호열이 올바름
    int res = 1;
    st = stack<char>();
    char prevCh = ' ';
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[') {
            if (ch == '(') res *= 2;
            else res *= 3;
        }
        else {
            if (ch == ')') {
                if (prevCh == '(') answer += res;
                res /= 2;
            }
            else {
                if (prevCh == '[') answer += res;
                res /= 3;
            }
        }
        prevCh = s[i];
    }

    if (!st.empty()) cout << 0 << endl;
    else cout << answer << endl;
}

int main() {
    fastio;
    input();
}
