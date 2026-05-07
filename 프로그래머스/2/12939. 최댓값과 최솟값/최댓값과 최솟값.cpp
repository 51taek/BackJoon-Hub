#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> v;
    int num;
    
    stringstream ss(s);
    
    while(ss >> num){
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size()-1]);
    
    return answer;
}