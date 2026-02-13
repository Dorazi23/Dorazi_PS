#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
bool chk[1000005];
vector<int> res, ans;
int t;

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

void func (vector<int>& res, int start, int cnt, int need) {
    if (cnt == need) {
        string s = "";
        for (auto x : res) s += (x+'0');
        int num = stoi(s);
        if (check(res)) ans.push_back(num);
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        if (cnt == 0 && i == 0) continue;
        res.push_back(i);
        func (res, i, cnt+1, need);
        res.pop_back();
    }
}

void func2 () {
    func(res, 0, 0, 3);
    func(res, 0, 0, 4);
    func(res, 0, 0, 5);
    func(res, 0, 0, 6);
}

void input () {
    int a, b, cnt = 0; cin >> a >> b;
    auto left = lower_bound (ans.begin(), ans.end(), a);
    auto right = upper_bound (ans.begin(), ans.end(), b);
    cout << right - left << endl;
}

int main() {
    fastio;
    func2();
    cin >> t;
    while (t--) {
        input();
    }
}