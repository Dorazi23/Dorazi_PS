#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> diff;
vector<int> time_set;
int n; ll lmt;
//전제 조건: times의 원소는 반드시 limit보다 작아야 한다.
//제한 시간 내에 퍼즐을 모두 해결할 수 있는 경우만 입력으로 주어집니다.
//total_time = (time_cur + time_prev) * (diff - level) + time_curr

bool solve(int level){
    ll tot = time_set[0];
    for(int i = 1; i < n; i++){
        int time_cur = time_set[i]; 
        int time_prev = time_set[i-1]; 
        if(level < diff[i]){ 
            tot += 1LL * (time_cur + time_prev) * (diff[i] - level) + time_cur;  
        }
        else{
            tot += time_cur;
        }
    }
    if(tot > lmt) return false;
    else return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    n = diffs.size(); //n개의 문제 
    lmt = limit;
    
    //외부에서 벡터 쓰기
    diff.assign(diffs.begin(), diffs.end()); 
    time_set.assign(times.begin(), times.end());
    
    if(n == 1) return 1; //문제가 하나면 전제조건에 의해 1이 최소 레벨이 됨
    
    int st = 0, en = 1e9; int md; //level range
    while(st + 1 < en){
        md = (st+en)/2; 
        if(solve(md)){
            en = md;
        }
        else{
            st = md;
        }
    }
    return en;
}

/*
n개의 퍼즐을 제한 시간 내 풀어야함
diff, time_cur time_prev, level

diff <= level: time_curr
diff > level
diff - level만큼 틀림, 틀릴 때마다 time_cur만큼 시간을 씀, 추가로 time_prev만큼 걸림(이전퍼즐은 틀리지 x)

time = (time_cur + time_prev) * (diff - level) + time_curr
현재 문제 걸린 시간: 2
이전 문제 걸린 시간: 4


diff = 3, time_cur = 2, time_prev = 4 : level의 최솟값


*/