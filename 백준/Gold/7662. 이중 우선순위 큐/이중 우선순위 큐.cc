#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int t, k;

unordered_multiset<int> valid;

bool check (int x) { // 있으면 참
    if (valid.find(x) != valid.end()) return true;
    else return false;
}

void input() {
    fastio; cin >> t;
    while(t--) {
        cin >> k;
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;
        valid.clear();
        while (k--) {
            char cmd; int num;
            cin >> cmd >> num;
            if (cmd == 'I') { // 입력
                maxheap.push(num);
                minheap.push(num);
                valid.insert(num);
            }
            else { // pop
                if (num == 1) { // D 1
                    while (true) { 
                        if (maxheap.empty()) break; // 큐가 비었으면 break
                        if (check(maxheap.top())) { // 값이 valid 하면 
                            valid.erase(valid.find(maxheap.top())); // invalid 하게 갱신
                            maxheap.pop(); // 큐에서 값을 제거
                            break;
                        }
                        else maxheap.pop();
                    }
                }
                else { // D -1
                    while (true) {
                        if (minheap.empty()) break;
                        if (check(minheap.top())) {
                            valid.erase(valid.find(minheap.top()));
                            minheap.pop();
                            break;
                        }
                        else minheap.pop();
                    }
                }
            }
        }
        if (valid.empty()) cout << "EMPTY" << endl;
        else {
            int mx = INT_MIN;
            int mn = INT_MAX;
            for (auto tar : valid) {
                mx = max(mx, tar);
                mn = min(mn, tar);
            }
            cout << mx << " " << mn << endl;
        }
    }
}

int main() {
    input();
}