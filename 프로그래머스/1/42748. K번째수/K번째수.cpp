#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++){
        vector<int> v;
        int st = commands[i][0] - 1;
        int en = commands[i][1];
        int po = commands[i][2] - 1;
        for(int j=st;j<en;j++){
            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());
        
        answer.push_back(v[po]);
    }
    
    return answer;
}