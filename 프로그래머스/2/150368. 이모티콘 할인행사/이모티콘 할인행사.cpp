#include <string>
#include <vector>

using namespace std;

int sale[4] = {10, 20, 30, 40};

int maxPrice = 0;
int maxN = 0;

void dfs(int idx, vector<int> &discount, vector<vector<int>> &users, vector<int> &emoticons){
    
    if(idx == emoticons.size()){
        int price = 0;
        int n = 0;
        
        for (int i = 0; i < users.size(); i++) {
            int minRate = users[i][0];  
            int limit = users[i][1];    
            int sum = 0;                

            for (int j = 0; j < emoticons.size(); j++) {
                if (discount[j] >= minRate) {
                    sum += emoticons[j] * (100 - discount[j]) / 100;
                }
            }

            if (sum >= limit) n++;      
            else price += sum;          
        }
        
        if(maxN < n){
            maxN = n;
            maxPrice = price;
        } else{
            if(maxN == n && maxPrice < price){
                maxPrice = price;
            }
        }
        return ;
    }
    
    for(int i=0;i<4;i++){
        discount[idx] = sale[i];
        dfs(idx+1, discount, users, emoticons);
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> discount(emoticons.size(), 0);
    
    dfs(0, discount, users, emoticons);
    
    answer.push_back(maxN);
    answer.push_back(maxPrice);
    
    return answer;
}