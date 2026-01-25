#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
stack<pair<int,int>> st;
int n;

void input () {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        if (st.empty()) {
            st.push({m, i});
            cout << "0 ";
        }
        else {
            // top이 m보다 클 때까지 pop 
            while (!st.empty() && st.top().X < m) {
                st.pop();
            }

            if (st.empty()) cout << "0 ";
            else cout << st.top().Y << " ";

            st.push({m, i});
        }
    }
}

int main() {
    fastio;
    input();
}