#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m;
int arr[2005];
bool dp[2005][2005];
// 2 * 10^6 * 10^3: 스택으로 불가능
// dp[i][j]: i~j까지 펠린드롬 여부

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];      
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
        dp[i][i+1] = arr[i] == arr[i+1];
    }
    
    for (int i = n - 1; i > 0; i--) {
        for (int j = i+2; j <= n; j++) {
            if (dp[i+1][j-1] == 1 && arr[i] == arr[j]) dp[i][j] = 1;
        }
    }
    
    cin >> m;
    while(m--){
        int s, e; cin >> s >> e;
        cout << dp[s][e] << endl;
    }
}

int main() {
    input();
}