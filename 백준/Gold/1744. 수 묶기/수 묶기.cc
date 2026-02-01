#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
priority_queue<int> ppq;
priority_queue<int, vector<int>, greater<int>> npq;
ll answer;

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        if (m == 1) answer++; // 1은 무조건 더하는 것이 이득 
        else if (m > 1) ppq.push(m);
        else npq.push(m);
    }
    
    int pcnt = ppq.size();
    int ncnt = npq.size();

    for (int i = 1; i <= pcnt/2; i++) { // i번 곱할 수 있음
        int a = ppq.top(); ppq.pop();
        int b = ppq.top(); ppq.pop();
        answer += (a*b);
    }
    if (!ppq.empty()) {
        answer += ppq.top(); ppq.pop();
    }
    
    for (int i = 1; i <= ncnt/2; i++) { // i번 곱할 수 있음
        int a = npq.top(); npq.pop();
        int b = npq.top(); npq.pop();

        // 경우의 수
        // 두 수가 음수 일 때: 이득
        // 둘 중 하나가 0일 때: 영향 없음
        // 모두 0일 때: 영향 없음
        
        answer += (a*b); 
    }
    if (!npq.empty()) {
        answer += npq.top(); npq.pop();
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}