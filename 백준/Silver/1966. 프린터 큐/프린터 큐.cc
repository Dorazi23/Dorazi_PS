#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int t;
deque<pair<int,int>> dq;
multiset<int, greater<int>> priority;

void input() {
    fastio;
    cin >> t;
    while (t--) {
        dq.clear();
        priority.clear();
        int n, target;
        cin >> n >> target;
        for (int i = 0; i < n; i++) {
            int p; cin >> p;
            dq.push_back({p,i}); // <중요도, 위치> 
            priority.insert(p);
        }
    
        int order = 0; // 순서
        while (!dq.empty()) {
            auto cur = dq.front(); dq.pop_front();
            // 찾으려는 값이면서 동시에, 우선순위도 일치할 때
            if (target == cur.Y && cur.X == *priority.begin()) {
                cout << order+1 << endl;
                break;
            }

            // 우선순위가 가장 높을 때
            if (cur.X == *priority.begin()) {
                // 현재 우선순위 삭제
                priority.erase(priority.begin()); 
                // 큐에 값도 추가하지 않음
                // 순서는 +1
                order++;
            }
            // 우선순위가 낮을 때, 
            else {
                // 큐에 값을 다시 추가함 (맨 뒤)
                dq.push_back(cur);
            }
        }
        
    }
}

int main() {
    input();
}