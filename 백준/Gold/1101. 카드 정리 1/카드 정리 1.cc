#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
int mxCnt = -100, joker, answer;
bool box[105][105], hasColor[105];
int cntColor[105]; // 해당 색을 가진 박스의 개수

void input () {
    cin >> n >> m;

    // i 번 박스에 j 종류 카드가 num 장 있다.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { 
            int num; cin >> num;
            if (num == 0) continue; // 카드가 0개면 넘김
            cntColor[j]++; // j 번째 카드를 가진 박스의 개수
            box[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;   
        for (int j = 1; j <= m; j++) {
            if (box[i][j]) cnt++;
        }

        if (cnt >= mxCnt && cnt > 0) {
            if (cnt > mxCnt) {
                joker = i;
                mxCnt = cnt;
            }
            else { // 가장 중복된 색상을 가진 
                vector<pair<int,int>> v;
                for (int k = 1; k <= m; k++) {
                    if (cntColor[k] == 0) continue;
                    v.push_back({cntColor[k], k}); // {색깔에 대한 박스 개수, 색깔}
                }
                sort(v.begin(), v.end(), greater<>());
                for (auto val : v) {
                    int color = val.Y;
                    bool I = box[i][color];
                    bool J = box[joker][color];
                
                    if ((I && J) || (!I && !J)) continue;
                    else if (I && !J) {
                        joker = i;
                        break;
                    }
                    else break;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) { // i 번째 박스에 대해
        if (i == joker) continue; // i 번째 박스가 조커면 넘김

        // 박스가 가진 색상의 개수를 따짐
        int cnt = 0, c = 0; // c는 색상이 하나인 경우를 고려하기 위함
        for (int j = 1; j <= m; j++) {
            if (box[i][j]) {
                cnt++;
                c = j;
            }
        }
        
        if (cnt > 1) { // 색상이 여러 종류인 박스
            answer++; // 싹 다 조커로 옮겨서 빈 박스로 만듦
        }
        else if (cnt == 1) { // 색상이 한 개인 박스
            // 해당 색상을 점유 중인 박스가 없으면 표시만 하고 끝
            if (!hasColor[c]) hasColor[c] = 1;
            else { // 해당 색상을 점유 중인 박스가 있으면 옮겨야 함 (조커 X)
                answer++;
            }
        }
        else continue; // 빈 박스는 건들이지 않음
    }
    cout << answer << endl;
}

int main() {
    fastio;
    input();
}