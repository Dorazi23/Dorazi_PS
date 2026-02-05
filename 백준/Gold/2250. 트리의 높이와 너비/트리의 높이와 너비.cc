#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 10005
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, root, cnt = 1;
int lc[MAX], rc[MAX], p[MAX];
vector<int> sq[MAX]; // [depth] = { } //번호 
void inorder(int cur, int depth){
    
    if(lc[cur] != -1) inorder(lc[cur], depth + 1);
    
    if(sq[depth].size() < 2){
        sq[depth].push_back(cnt);
    }
    else{
        sq[depth].pop_back();
        sq[depth].push_back(cnt);
    }
    cnt++;
    if(rc[cur] != -1) inorder(rc[cur], depth + 1);
}

int main() {
    memset(p, -1, sizeof(p));
    fastio; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        lc[a] = b; rc[a] = c;
        if(b != -1) p[b] = a;
        if(c != -1) p[c] = a;
    }
    for (int i = 1; i <= n; i++) {
        if(p[i] == -1){
            root = i;
        }
    }
    inorder(root, 1);
    int ans_mx = 0, ans_depth;
    for (int i = 1; sq[i].size() != 0; i++) {
        if(sq[i].size() == 1) continue;
        int val = sq[i][1] - sq[i][0] + 1;
        if(val > ans_mx){
            ans_mx = val;
            ans_depth = i;
        }
    }
    if(ans_mx == 0) cout << 1 << " " << 1 << endl;
    else cout << ans_depth << " " << ans_mx << endl;
}