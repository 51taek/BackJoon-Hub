#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int,int> m;
    vector<int> v;
    
    for(int i=0;i<tangerine.size();i++){
        m[tangerine[i]]++;
    }
    
    for(int i=0;i<m.size();i++){
        v.push_back(m[i]);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    for(int j: v){
        
        k -= j;
        answer++;
        
        if(k<=0) break;
    }
    
    
    return answer;
}