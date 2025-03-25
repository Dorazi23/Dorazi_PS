#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(1){
        if(pq.size() == 1){
            if(pq.top() >= k){
                return answer;
            }
            else{
                return -1;
            }
        }
        
        if(pq.top() < k){ //가장 작은 값이 k보다 작을 때
            int val1 = pq.top(); pq.pop(); //가장 작은 값
            int val2 = pq.top(); pq.pop(); //두 번째로 작은 값
            int mix = val1 + (val2 * 2); //연산
            pq.push(mix);
            answer++;
            continue;
        }
        else{ //모든 값이 k보다 클 때
            return answer; 
        }
    }
}



/*
모든 음식의 스코빌 지수를 k 이상
스코빌 지수가 가장 낮은 두 음식을 아래 방법으로 섞기
섞음 음식 스코빌 지수 = 최솟값 + (그 다음 최솟값 * 2)

배열의 모든 값을 K 이상으로 만들기 위한 최소 횟수

1 2 3 9 10 12
1 + 2*2 = 5

3 5 9 10 12
3 + 5*2 = 13

K = 7
9 10 12 13


로직
1. 벡터를 정렬
2. 모든 원소가 K 이상인지 확인 
- 맞으면 answer 출력
3. 맨 앞 2개의 원소를 pop하고 공식대로 처리후 push 

*/


