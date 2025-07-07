#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    do{
        int p = k;
        int r = 0;
        for(int i=0; i<dungeons.size();i++){
            if(dungeons[i][0] <= p){
                p -= dungeons[i][1];
                r++;
            }
        }
        answer = max(answer,r);
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}