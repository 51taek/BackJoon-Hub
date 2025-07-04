#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int big[10002];
    int small[10002];
    
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0] < sizes[i][1]){
            big[i] = sizes[i][1];
            small[i] = sizes[i][0];
        }else {
            big[i] = sizes[i][0];
            small[i] = sizes[i][1];
        }
    }
    
    int a = 0;
    int b = 0;
    
    for(int i=0;i<sizes.size();i++){
        if(a < big[i]){
            a = big[i];
        }
        
        if(b < small[i]){
            b = small[i];
        }
    }
    
    return a * b;
}