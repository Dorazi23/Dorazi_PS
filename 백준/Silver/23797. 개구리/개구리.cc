#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
string s;
unordered_multiset<bool> ms;
// ms는 중복된 값이 전부 지워지므로, iterator 명시해서 특정 값만 삭

void input () {
    cin >> s;

    int n = 0; // 현재 마릿 수 
    for (auto ch : s) {
        if (ch == 'K') { // 0
            auto it = ms.find(1);
            if(it != ms.end()) { // 1이 존재하면 
                ms.erase(it);
                ms.insert(0);
            }
            else { // 개구리 추가 
                n++;
                ms.insert(0);
            }
        }
        else { // 1
            auto it = ms.find(0);
            if(it != ms.end()) { // 0이 존재하면
                ms.erase(it);
                ms.insert(1);
            }
            else { // 개구리 추가
                n++;
                ms.insert(1);
            }
        }
    }

    cout << n << endl;
}

int main() {
    fastio;
    input();
}