#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, m, arr[1005];
deque<tuple<int,int,int>> dq;

void input () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> arr[i];

    int idx = 0;
    for (int i = 0; i < m; i++) {
        int student = arr[i];

        if (dq.empty()) {
            dq.push_back({1, idx++, student});
            continue;
        }
        
        bool flag = false;
        for (auto& [cnt, ord, stu] : dq) {
            if (stu == student) {
                cnt++;
                flag = true;
                break;
            }
        }

        sort(dq.begin(), dq.end(), greater<>());
        if (!flag) {
            if (dq.size() < n) dq.push_back({1, idx++, student});
            else {
                dq.pop_back();
                dq.push_back({1, idx++, student});
            }
        }
    }

    vector<int> v;
    for (auto [cnt, ord, stu] : dq) v.push_back(stu);

    sort(v.begin(), v.end());
    for (auto x : v) cout << x << " ";
}

int main() {
    fastio;
    input();
}