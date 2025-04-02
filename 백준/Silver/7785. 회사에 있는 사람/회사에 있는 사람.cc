#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    unordered_set<string> s;
    while(n--) {
        string name, log; cin >> name >> log;
        if(log == "enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for (auto x : ans) cout << x << endl;
}