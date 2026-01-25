#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
stack<pair<int,int>> st;
ll answer;

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        if (st.empty()) st.push({m, 1});
        else {
            int cnt = 1;
            while (!st.empty() && st.top().X <= m) {
                answer += st.top().Y;
                if (st.top().X == m) cnt += st.top().Y;
                st.pop();
            }
            if (!st.empty()) answer++;
            st.push({m, cnt});
        }
    }
    cout << answer << endl;
}

int main() {
    fastio;
    input();
}