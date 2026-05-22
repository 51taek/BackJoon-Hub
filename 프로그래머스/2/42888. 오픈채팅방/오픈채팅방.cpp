#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string,string> m;
    
    for(string s: record){
        stringstream ss(s);
        string active;
        string uuid;
        string name;
        
        ss >> active >> uuid >> name;
        
        if(active == "Enter") m[uuid] = name;
        else if(active == "Change") m[uuid] = name;
    }
    
    for(string s: record){
        string ns = "";
        stringstream ss(s);
        string active;
        string uuid;
        string name;
        
        ss >> active >> uuid >> name;
        
        if(active == "Enter"){
            ns += m[uuid];
            ns += "님이 들어왔습니다.";
        }else if(active == "Leave"){
            ns += m[uuid];
            ns += "님이 나갔습니다.";
        } else if(active == "Change"){
            continue;
        }
        answer.push_back(ns);
    }
    
    
    return answer;
}