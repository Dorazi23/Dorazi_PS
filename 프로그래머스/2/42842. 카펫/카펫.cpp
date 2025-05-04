#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int y = 1; y <= yellow; y++){
        int x;
        if(yellow % y == 0){
            x = yellow / y;
            if(x <= y && 2*(x+y)+4 == brown){
                answer.push_back(y+2);
                answer.push_back(x+2);
            }
        }
    }
    return answer;
}