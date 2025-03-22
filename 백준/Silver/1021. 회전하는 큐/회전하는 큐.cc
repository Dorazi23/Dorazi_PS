#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 10000
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, m, cnt;
vector<int> ans;
int main() {
    fastio;
    cin >> n >> m;
    deque<int> dq;
    for (int i = n; i >= 1; i--) {
        dq.push_front(i);
    }
    for (int i = 0; i < m; i++) {
        int tar; cin >> tar;
        auto iter = find(dq.begin(), dq.end(), tar) - dq.begin();
        while(!dq.empty()){
            if(dq.front() == tar){ //값을 찾았다면
                dq.pop_front();
                break;
            }
            if(iter > dq.size() / 2){ //tar가 덱의 뒤에 있다
                for (int i = 0; i < dq.size() - iter; i++) {
                    int val = dq.back();
                    dq.pop_back();
                    dq.push_front(val);
                    cnt++;
                }
            }
            else{ //tar가 덱의 앞에 있다
                for (int i = 0; i < iter; i++) {
                    int val = dq.front();
                    dq.pop_front();
                    dq.push_back(val);
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}