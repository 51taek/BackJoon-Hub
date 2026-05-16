#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    map<int,int> answer;
    
    string num = "";

    for(char c: s){
        if(isdigit(c)){
            num += c;
        }else{
            if(!num.empty()){
                answer[(stoi(num))]++;
                num = "";
            }
        }
    }
    
    vector<pair<int, int>> v;

    for(auto p : answer){
        v.push_back({p.second, p.first});
    }

    sort(v.rbegin(), v.rend());

    vector<int> ans;

    for(auto p : v){
        ans.push_back(p.second);
    }

    return ans;
    
    return ans;
}