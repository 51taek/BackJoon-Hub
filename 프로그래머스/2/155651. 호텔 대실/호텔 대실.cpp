#include <string>
#include <vector>
#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.X == b.X) return a.Y < b.Y;
    else return a.X < b.X;
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    
    vector<pair<int,int>> v;
    
    for(int i=0;i<book_time.size();i++){
        string st = book_time[i][0];
        string en = book_time[i][1];
        
        string st_h = st.substr(0,2);
        string st_m = st.substr(3,2);
        string en_h = en.substr(0,2);
        string en_m = en.substr(3,2);
        
        int start = stoi(st_h) * 60 + stoi(st_m);
        int end = stoi(en_h) * 60 + stoi(en_m);
        
        v.push_back({start,end+10});
    }
    
    sort(v.begin(), v.end(), compare);
    
    int now = 0;
    for(int i=0;i<v.size();i++){
        if(now < v[i].X){
            now = v[i].Y;
        }else{
            answer++;
        }
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < v.size(); i++) {
        int start = v[i].first;
        int end = v[i].second;
        
        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }
        
        pq.push(end);
    }
    
    return pq.size();
}