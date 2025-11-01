#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[30][30];
int dp[3][30][30] = {0, };
int ans[30][30] = {0, };
int n;

bool OutOfBounds(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= n;
}

bool Diagonal_Possible(int x, int y){ //해당 좌표를 끝으로 하는 대각선이 가능한지 확인
    if (OutOfBounds(x,y) || OutOfBounds(x-1,y) || OutOfBounds(x,y-1) || OutOfBounds(x-1,y-1)) return false;
    if (board[x][y] == 1 || board[x-1][y] == 1 || board[x][y-1] == 1 || board[x-1][y-1] == 1) return false;
    return true;
}

bool Row_Possible(int x, int y){ 
    if(OutOfBounds(x,y) || OutOfBounds(x,y-1)) return false;
    if(board[x][y] == 1 || board[x][y-1] == 1) return false;
    return true;
}

bool Col_Possible(int x, int y){
    if(OutOfBounds(x,y) || OutOfBounds(x-1,y)) return false;
    if(board[x][y] == 1 || board[x-1][y] == 1) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    if (board[n-1][n-1] == 1){
        cout << "0" << endl;
        return 0;
    }
  
    dp[0][0][1] = 1;    

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if(x == 0 && y == 0) continue;
            if(x == 0 && y == 1) continue;
            
            // (x,y)는 다음 위치
            if(board[x][y] == 1) continue; // 벽이면 스킵
 
            // x-1, y
            // 1. 세로 -> 세로
            if (Col_Possible(x-1, y)) {
                dp[1][x][y] += dp[1][x-1][y];
            }
    
            // 2. 대각선 -> 세로
            if(Diagonal_Possible(x-1, y)){
                dp[1][x][y] += dp[2][x-1][y];
            }
                
            // x, y-1
            // 1. 가로 -> 가로
            if (Row_Possible(x, y-1)) {
                dp[0][x][y] += dp[0][x][y-1];    
    
            }
                
            // 2. 대각선 -> 가로
            if(Diagonal_Possible(x, y-1)){
                dp[0][x][y] += dp[2][x][y-1];
            }
            
    
            // x-1, y-1
            if (Diagonal_Possible(x,y)){
                // 1. 가로 -> 대각선
                if (Row_Possible(x-1, y-1)) {
                    dp[2][x][y] += dp[0][x-1][y-1];
                }
                // 2. 세로 -> 대각선
                if (Col_Possible(x-1, y-1)) {
                    dp[2][x][y] += dp[1][x-1][y-1];                    
                }
                    
                // 3. 대각선
                if(Diagonal_Possible(x-1, y-1)){
                    dp[2][x][y] += dp[2][x-1][y-1];
                }   
            }   
        }
    }
        
    int sum = dp[0][n-1][n-1] + dp[1][n-1][n-1] + dp[2][n-1][n-1];
    cout << sum << endl;
}