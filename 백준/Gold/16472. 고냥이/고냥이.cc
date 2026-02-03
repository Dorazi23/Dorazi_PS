#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, tot, mx = -1000, alphabet[30];
string s;

void input () {
    cin >> n >> s; 
    int st = 0, en = 0, cnt = 0;
    while (st <= en && en < s.size()) {
        char ch = s[en];
        int numOfAlphabet = ch - 'a';
        if (alphabet[numOfAlphabet] > 0) {
            tot++;
            alphabet[numOfAlphabet]++;
            en++;
        }
        else {
            if (cnt < n) { // 수용 가능 
                cnt++;
                tot++;
                alphabet[numOfAlphabet]++;
                en++;
            } 
            else {
                mx = max (mx, tot); 
                // 문자열의 종류를 하나 줄임 
                while (cnt == n) {
                    // 마주치는 모든 문자의 개수를 줄임 
                    alphabet[s[st] - 'a']--; 
                    tot--;
                    if (alphabet[s[st] - 'a'] == 0) {
                        cnt--;
                    }
                    st++;
                }
            }
        }
    }
    mx = max (mx, tot);
    cout << mx << endl;
}

int main() {
    fastio;
    input();
}