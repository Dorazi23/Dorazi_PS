#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int sz = prices.size();
    for(int i = 0; i < sz; i++){
        int len = 0;
        for(int j = i+1; j < sz; j++){
            len++;
            if(prices[i] > prices[j]){ 
                break;
            }
        }
        answer.push_back(len);
    }
    return answer;
}
/*
LIS
i번째일 때 i+1 번째부터 끝까지 본인보다 연속된 큰 수의 개수를 센다
만약에 바로 끊긴다면 유지를 한 것이므로 1초가 된다
배열의 마지막은 0초이다

vector<int> answer;
    return answer;
*/