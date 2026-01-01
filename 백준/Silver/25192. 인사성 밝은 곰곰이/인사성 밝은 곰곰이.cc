#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
unordered_set<string> arr[100005];
vector<string> v;

void input() {
    fastio; cin >> n;
    while (n--) {
        string s; cin >> s;
        v.push_back(s);
    }

    int idx = 0;
    for (auto val : v) {
        if (val == "ENTER") {
            idx++;
        }
        else {
            arr[idx].insert(val);
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= 100000; i++) {
        if (arr[i].size() == 0) break;
        answer += arr[i].size();
    }

    cout << answer << endl;
}

int main() {
    input();
}