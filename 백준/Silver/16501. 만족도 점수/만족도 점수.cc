#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000007
#define INF 4e18
using namespace std;
using ll = long long;
vector<int> temp; 
vector<float> value;
float answer = -1000;

float func (float x, float y) { // 두 팀의 총합
    float res = 1 - (abs((x/2)-(y/2)) / 10);
    return res;
}

void input () {
    for (int i = 0; i < 8; i++) {
        float m; cin >> m;
        temp.push_back(i);
        value.push_back(m);
    }
    sort(temp.begin(), temp.end());
    
    do {
        float val;
        
        // 8!의 순열을 2,2 vs 2,2로 묶어 계산 
        float teamA = value[temp[0]] + value[temp[1]];
        float teamB = value[temp[2]] + value[temp[3]];
        float teamC = value[temp[4]] + value[temp[5]];
        float teamD = value[temp[6]] + value[temp[7]];

        // 두 팀의 만족도 중 더 작은 값을 택함
        val = min(func(teamA, teamB), func(teamC, teamD));

        // 그 작은 값의 상한선을 구함
        answer = max(answer, val);
    } while (next_permutation(temp.begin(), temp.end()));

    cout << fixed;
    if (int(answer * 10) == answer * 10) cout.precision(1);
	else cout.precision(2);
    cout << answer << endl;
}

int main() {
    fastio;
    input();
}