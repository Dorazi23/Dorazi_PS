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
priority_queue<int> pq;

void input() {
    fastio; cin >> n;
    while(n--) {
        int num; cin >> num;

        // 선물 분배 
        if (num == 0) {
            if (pq.empty()) { // 나눠줄 선물이 없음
                cout << "-1" << endl; 
                continue;
            }
            else { // 선물이 있으면 가장 큰 값 
                cout << pq.top() << endl;
                pq.pop();
            }
        }

        // 선물 충전 
        else {
            while (num--) { // num만큼 충전 
                int tmp; cin >> tmp;
                pq.push(tmp);
            }
            
        }
    }
}

int main() {
    input();
}