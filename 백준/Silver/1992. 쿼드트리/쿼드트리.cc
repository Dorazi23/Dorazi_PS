#include <bits/stdc++.h>
#define endl '\n'
#define MIN -100000
#define MAX 1000005
using namespace std;
string arr[129]; 
int n;
void dfs(int x, int y, int len){
    bool cut = false;
    char color = arr[x][y];
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if(color != arr[i][j]){
                cut = true;
                break;
            }
        }
    }

    if(!cut){ //x
        if(color == '0'){
            cout << "0";
            return;
        }
        else{
            cout << "1";
            return;
        }
    }
    else{ //o
        int next_len = len / 2;
        cout << "(";
        dfs(x, y, next_len);
        dfs(x, y + next_len, next_len);
        dfs(x + next_len, y, next_len);
        dfs(x + next_len, y + next_len, next_len);
        cout << ")";
    }
}

int main(void) {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dfs(0,0,n);
}