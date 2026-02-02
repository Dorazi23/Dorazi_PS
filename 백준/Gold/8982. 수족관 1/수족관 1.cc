#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, k, a, b, c, d;
ll answer;
pair<int,int> depth[40005];
vector<int> hole;

void input () {
    cin >> n;

    cin >> a >> b; // 처음 
    for (int i = 1; i < n/2; i++) {
        cin >> a >> b >> c >> d; 
        // 동일한 바닥은 같은 높이로 채우기
        for (int j = a; j < c; j++) depth[j].X = b;
    }
    cin >> a >> b; // 마지막 
    int last = a; // 수족관의 가로 길이 
    
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c >> d;
        hole.push_back(a); // 시작 열만 저장
    }

    for (int i = 0; i < k; i++) {
        int x = hole[i];
        int drain_depth = depth[x].X; // 물이 빠질 정도
        depth[x].Y = drain_depth;
        
        for (int i = x-1; i >= 0; i--) {
            // 턱이 있으면 물이 빠질 수 있는 정도가 낮아짐 
            drain_depth = min(drain_depth, depth[i].X); 
            // 빠질 수 있는 정도에서 최대를 골라야 함
            depth[i].Y = max(depth[i].Y, drain_depth);
        }

        drain_depth = depth[x].X;
        for (int i = x+1; i < last; i++) {
            drain_depth = min(drain_depth, depth[i].X); 
            depth[i].Y = max(depth[i].Y, drain_depth);
        }
    }
    
    for (int i = 0; i < last; i++) {
        // cout << (depth[i].X - depth[i].Y) << " ";
        answer += (depth[i].X - depth[i].Y);
    }
    cout << answer << endl;
}

int main() {
    fastio;
    input();
}