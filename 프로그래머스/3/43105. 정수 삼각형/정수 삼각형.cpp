#include <bits/stdc++.h>
using namespace std;
int dp[505][1005];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    memset(dp, -1, sizeof(dp));
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = 0;
            
            if(j == 0){
                dp[i][0] = dp[i-1][0] + triangle[i][j];
            }
            else if(0 < j && j < i){
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        answer = max(answer, dp[n-1][i]);
    }
    return answer;
}