#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, answer;
string s;
vector<string> ring;

void input () {
    fastio; cin >> s >> n;
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        t += t;
        ring.push_back(t);
    }

    for (auto val : ring) {
        if(val.find(s) != string::npos) answer++;
    }

    cout << answer << endl;
}

int main() {
    input();
}