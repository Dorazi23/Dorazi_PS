#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
string w;
int t, k, mx, mn;
int alphabet[100];

void input () {
    fastio; cin >> t;
    while (t--) {
        // 반복되는 요소 초기화 
        bool flag = false;
        memset(alphabet, 0, sizeof(alphabet));
        mx = -1000, mn = MAX;
        
        cin >> w >> k; 
        
        for (int i = 0; i < w.size(); i++) { // 알파벳 개수 파악 
            alphabet[w[i] - 'a']++;
        }
    
        for (int i = 0; i < w.size(); i++) {
           
            if (alphabet[w[i] - 'a'] < k) continue; // 문자가 1개 이하인 경우엔 스킵 
    
            char tar = w[i]; 
            int len = 1, cnt = 1; // len: 문자열의 길이, cnt: tar이 나온 횟수 
            
            
            for (int j = i + 1; j < w.size(); j++) {
                flag = true; // 한 번이라도 루프를 돌면 가능한 경우가 존재함 
                if (cnt < k) { // k번보다 적게 나왔다면 
                    if (tar == w[j]) {
                        cnt++;
                        len++;
                    }
                    else len++;
                }
            }
            if (cnt == k) {
                mx = max (mx, len);
                mn = min (mn, len);    
            }
        }
    
        if (!flag) { // 한 번도 루프가 돌지 않음 
            if (w.size() == 1) cout << "1 1" << endl;
            else cout << "-1" << endl; 
        }  
        else cout << mn << " " << mx << endl;
    }
}

int main() {
    input();
}