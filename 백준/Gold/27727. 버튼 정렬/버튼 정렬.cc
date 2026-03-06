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
unordered_map<int, int> ms;
vector<int> nlist; // 순서가 유지될 리스트
deque<pair<int,int>> num_count; 
ll k, answer;

void input () {
    fastio; cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nlist.push_back(num);
    }
    cin >> k;
    ll tmp = k;
    
    if (n == 1) { // n = 1일 때 
        cout << k << endl;
        return;
    }

    // 평탄화 범위 찾기 
    int last_idx = 0;
    int cur_mx = -1000;
    int tar_height = 0;
    for (int i = 0; i < nlist.size(); i++) {
        if (nlist[i] < cur_mx) {
            last_idx = i;
            tar_height = cur_mx;
        }
        if (nlist[i] > cur_mx) cur_mx = nlist[i];
    }

    // 평탄화 진행 
    for (int i = 0; i <= last_idx; i++) {
        if (nlist[i] < tar_height) {
            k -= (tar_height - nlist[i]);
            nlist[i] = tar_height;
        }
    }

    if (k < 0) { // 평탄화를 마쳤더니 가능 횟수가 음수라면 평탄화가 불가능
        cout << "0" << endl;
        return;
    }
    else if (k == 0) { // 평탄화를 마쳤더니 가능 횟수가 0이면 1
        cout << "1" << endl;
        return;
    }
    else { // 평탄화를 마쳤더니 가능 횟수가 양수라면 -> 더 합산 가능
        // 버튼 횟수가 깎였다면, 평탄화가 진행된 것
        if (tmp != k) answer = 1; 
        
        for (auto val : nlist) {
            ms[val]++;
        }
        
        for (auto val : ms) {
            num_count.push_back({val.X, val.Y});
        }
        
        sort (num_count.begin(), num_count.end());
        
        while (num_count.size() > 1) { 
            auto [x, c] = num_count.front(); num_count.pop_front();
            auto [nx, nc] = num_count.front();

            ll diff = nx - x;
            ll need = diff * c;

            if (need <= k) {
                num_count.pop_front();
                k -= need;
                answer += diff;
                num_count.push_front({nx, c + nc});
            }
            else {
                answer += (k / c);
                k = 0;
                break;
            }
        }

        if (k <= 0) cout << answer << endl;
        else {
            auto val = num_count.front();
            answer += (k / val.Y);
            cout << answer << endl;
        }
    }
}

int main() {
    input();
}