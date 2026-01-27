#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int answer[100005];
bool prime[100005];

void isPrime() {
    prime[1] = 1;
    for (int i = 2; i <= 100002; i++) {
        if (prime[i]) continue;
        for (int j = 2; i*j <= 100002; j++) {
            prime[i*j] = 1;
        }
    }
}

bool func (string s) { // 참이면 좋은 성질 수
    string tmp = s;
    string val = "";
    for (int i = 0; i < s.size(); i++) {
        val.push_back(s[i]);
        tmp.erase(tmp.begin());

        int a = stoi(val);
        int b = 0;
        if (tmp.size() == 0) b = 1;
        else b = stoi(tmp);

        // 합성수면 좋은 성질 수가 아님 
        if (prime[a*b+1]) return false;
    }

    return true;
}

void ans () {
    answer[1] = 1;
    for (int i = 2; i <= 100002; i++) {
        if (func(to_string(i))) answer[i] = answer[i-1] + 1;
        else answer[i] = answer[i-1];
    }
}

void input () {
    int n; cin >> n;
    cout << answer[n] << endl;
}

int main() {
    fastio;
    isPrime();
    ans();

    int T; cin >> T;
    while (T--) {
        input();   
    }
}
