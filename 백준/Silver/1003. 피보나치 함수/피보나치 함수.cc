#include <bits/stdc++.h>
using namespace std;
int d[1005][2];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    d[0][0] = 1;
    d[0][1] = 0;
        
    d[1][0] = 0;
    d[1][1] = 1;
        
    for (int i = 2; i < 41; i++) {
        d[i][0] = d[i-1][0] + d[i-2][0];
        d[i][1] = d[i-1][1] + d[i-2][1];
    }
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << d[n][0] << " " << d[n][1] << '\n';
    }
}