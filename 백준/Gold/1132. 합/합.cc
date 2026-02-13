#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
int n, zero = -1, value[30];
ll digits[30];
bool first[30]; // 맨 앞에 나온 글자

void input () {    
    cin >> n;
    while (n--) {
        string s; cin >> s;
        first[s[0]-'A'] = 1; // 맨 앞에 나온 글자
        ll idx = 1;
        for (int i = s.size()-1; i >= 0; i--) {
            char ch = s[i];
            digits[ch-'A'] += idx;
            idx *= 10;
        }
    }
    // 모든 알파벳이 쓰였는지 확인 
    // 참이면 0을 안 넣어도 됨
    bool flag = false; 
    vector<pair<ll,int>> v; // {값, 인덱스}
    for (int i = 0; i < 10; i++) {
        if (digits[i] == 0) flag = true;
        else v.push_back({digits[i], i});
    }
    sort(v.begin(), v.end(), greater<>()); // 내림차순 정렬하여 9부터 할당

    if (!flag) { // 0을 반드시 넣어야 하는 경우 
        // 내림차순 돼있으므로, 가장 끝 쪽에 first가 아닌 최솟값 선택
        for (int i = v.size()-1; i >= 0; i--) { // {값, 인덱스}
            auto idx = v[i].Y;
            if (!first[idx]) {
                zero = idx;
                break;
            }
        }
    }
    int order = 9;
    ll answer = 0;
    for (auto val : v) {
        ll tot = val.X; // 자릿수
        int idx = val.Y; // 인덱스
        if (idx == zero) continue;
        answer += (order * tot);
        order--;
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}