#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
int n, m, k;
string s;
vector<string> v;

void input () {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> s; 
        sort(s.begin(), s.end());
        v.push_back(s);
    }
    sort(v.begin(), v.end());

    s = "";
    for (int i = 0; i < k; i++) {
        s += v[i];
    }

    sort(s.begin(), s.end());
    cout << s << endl;
}

int main() {
    fastio;
    input();
}