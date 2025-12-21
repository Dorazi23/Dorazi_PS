#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
unordered_map<string, int> poketmonTonum;
unordered_map<int, string> numTopoketmon;

void input() {
    fastio; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        poketmonTonum[s] = i;
        numTopoketmon[i] = s;
    }

    while (m--) {
        string s; cin >> s;
        if (isdigit(s[0])) { // 입력이 숫자
            int num = stoi(s);
            cout << numTopoketmon[num] << endl;
        }
        else { // 입력이 문자열
            cout << poketmonTonum[s] << endl;
        }
    }
}

int main() {
    input();
}