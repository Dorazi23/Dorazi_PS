#include <bits/stdc++.h>
#define INF 1000000
using namespace std;
using ll = long long;
int n;
int arr[1005][4];
ll dp[1005][4][4];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
}

void ans(){
    
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < n; i++) {
        
        // (중간) 0번째 색이 k일 때 i번째 색을 j로 칠할 때
        if (1 < i && i < n-1) {
            dp[i][0][0] = min(dp[i-1][1][0], dp[i-1][2][0]) + arr[i][0]; 
            dp[i][0][1] = min(dp[i-1][1][1], dp[i-1][2][1]) + arr[i][0];  
            dp[i][0][2] = min(dp[i-1][1][2], dp[i-1][2][2]) + arr[i][0];
            
            dp[i][1][0] = min(dp[i-1][0][0], dp[i-1][2][0]) + arr[i][1]; 
            dp[i][1][1] = min(dp[i-1][0][1], dp[i-1][2][1]) + arr[i][1]; 
            dp[i][1][2] = min(dp[i-1][0][2], dp[i-1][2][2]) + arr[i][1]; 
            
            dp[i][2][0] = min(dp[i-1][0][0], dp[i-1][1][0]) + arr[i][2]; 
            dp[i][2][1] = min(dp[i-1][0][1], dp[i-1][1][1]) + arr[i][2];
            dp[i][2][2] = min(dp[i-1][0][2], dp[i-1][1][2]) + arr[i][2]; 
        }

        // (마지막) 0번째 색이 k일 때 n-1번째 색을 j로 칠할 때
        else if (i == n-1) {
            
            dp[i][0][1] = min(dp[i-1][1][1], dp[i-1][2][1]) + arr[i][0];
            dp[i][0][2] = min(dp[i-1][1][2], dp[i-1][2][2]) + arr[i][0]; 
            
            dp[i][1][0] = min(dp[i-1][0][0], dp[i-1][2][0]) + arr[i][1];
            dp[i][1][2] = min(dp[i-1][0][2], dp[i-1][2][2]) + arr[i][1];
            
            dp[i][2][0] = min(dp[i-1][0][0], dp[i-1][1][0]) + arr[i][2];
            dp[i][2][1] = min(dp[i-1][0][1], dp[i-1][1][1]) + arr[i][2];
        }

        // (두 번째)
        else if (i == 1) {
            dp[i][0][1] = dp[0][1][1] + arr[i][0];
            dp[i][0][2] = dp[0][2][2] + arr[i][0];

            dp[i][1][0] = dp[0][0][0] + arr[i][1];
            dp[i][1][2] = dp[0][2][2] + arr[i][1];

            dp[i][2][0] = dp[0][0][0] + arr[i][2];
            dp[i][2][1] = dp[0][1][1] + arr[i][2];
        }
            
        // (첫 번째) 0번째 색이 0일 때, 0 번째 색을 0번째로 칠할 때 
        else{
            dp[0][0][0] = arr[0][0];
            dp[0][1][1] = arr[0][1];
            dp[0][2][2] = arr[0][2];
        }
    }
}

int main() {
    input();
    ans();

    int m1 = min(dp[n-1][0][1], dp[n-1][0][2]);
    int m2 = min(dp[n-1][1][0], dp[n-1][1][2]);
    int m3 = min(dp[n-1][2][0], dp[n-1][2][1]);
    cout << min(min(m1, m2), m3);
}