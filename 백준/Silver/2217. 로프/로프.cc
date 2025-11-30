#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
vector<int> rope;

void input() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num; rope.push_back(num);
    }
    sort(rope.begin(), rope.end());
}

// w/k 일 때, k개의 원소 중 가장 작은 값으로 들 수 있으면 가능하다 

bool check(int md) { 
    // md는 들어야하는 무게
    // n개를 모두 사용하는 케이스부터 1개만 쓰는 케이스까지 고려한다
    // 로프는 오름차순 정렬돼있으므로, 가장 약한 로프부터 테스트
    // 가장 약한 로프로 w/k가 가능하면 그 케이스는 통과
    for (int i = n; i >= 1; i--) { // 사용하는 밧줄의 개수  
        int tmp = md/i;
        if (md % i != 0) tmp++; // 10.5 같은 상황에서는 10으로 들 수 없음
        if (tmp <= rope[abs(i-n)]) return true;
    }
    return false;
}


void ans() {
    int st = 0, en = 1e9;
    while (st+1 < en) {
        int md = (st+en) / 2;
        if (check(md)) {
            st = md;
        }
        else {
            en = md;
        }
    }

    cout << st << endl;
}

int main() {
    input();
    ans();
}