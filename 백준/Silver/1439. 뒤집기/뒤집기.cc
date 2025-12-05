#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
string s;

int one_cnt;
int zero_cnt;

int main() {
    fastio; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] != s[i-1]) {
            if (s[i] == '0') zero_cnt++;
            else one_cnt++;
        }
    }
    cout << min(zero_cnt, one_cnt);
}