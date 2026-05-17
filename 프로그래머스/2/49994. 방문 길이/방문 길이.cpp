#include <string>
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int solution(string dirs) {
    int answer = 0;
    
    pair<int,int> p;
    p = {0,0};
    
    set < pair <pair<int,int>, pair<int,int>> > visited;
    
    for(char c : dirs){
        pair<int,int> before = p;
        pair<int,int> next = p;

        if(c == 'U'){
            next.Y++;
        } else if(c == 'D'){
            next.Y--;
        } else if(c == 'L'){
            next.X--;
        } else if(c == 'R'){
            next.X++;
        }

        if(next.X < -5 || next.X > 5 || next.Y < -5 || next.Y > 5){
            continue;
        }
        
        visited.insert({before, next});
        visited.insert({next, before});

        p = next;
    }
    
    
    return visited.size() / 2;
}