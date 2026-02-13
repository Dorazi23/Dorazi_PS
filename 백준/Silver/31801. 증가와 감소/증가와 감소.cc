#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
vector<int> res;
int t, dp[1000005];

bool check (vector<int>& v) {    
    int tar = -1;
    for (int i = 0; i < v.size()-1; i++) {
        if (v[i] > v[i+1]) { // 감소하는 구간 포착 
            tar = i;
            break;
        }
    }

    // 감소하는 구간이 없거나, 처음이면 안됨
    if (tar == -1 || tar == 0) return false; 
    else {
        // 증가하는 구간에서 감소하면 안됨
        for (int i = 0; i <= tar; i++) {
            if (i <= tar-1 && v[i] >= v[i+1]) return false;
        }
        
        // 감소하는 구간에서 증가하면 안됨
        for (int i = tar; i <= v.size()-2; i++) {
            if (v[i] <= v[i+1]) return false;  
        }
        
        return true;
    }
}

void func (vector<int>& res, int cnt, int need) {
    if (cnt == need) {
        int num = 0;
        for (auto x : res) num = (num * 10 + x);

        dp[num] = dp[num-1];
        if (check(res)) dp[num]++;
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        if (cnt == 0 && i == 0) continue;
        res.push_back(i);
        func (res, cnt+1, need);
        res.pop_back();
    }
}

void input () {
    int a, b; cin >> a >> b;
    cout << dp[b] - dp[a-1] << endl;
}

int main() {
    fastio;
    for (int i = 3; i <= 6; i++) func(res, 0, i);
    dp[1000000] = dp[999999]; // 누적합 이어주기
    cin >> t;
    while (t--) {
        input();
    }
}