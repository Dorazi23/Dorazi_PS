#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

string s;
unordered_set<string> u;

void input () {
    fastio; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        string tmp(1, s[i]);
        u.insert(tmp);
        for (int j = i+1; j < s.size(); j++) {
            tmp.push_back(s[j]);
            u.insert(tmp);
        }
    }

    cout << u.size() << endl;
}

int main() {
    input();
}