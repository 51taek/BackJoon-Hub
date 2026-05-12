#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    list<string> cache;
    
    if (cacheSize == 0) return cities.size() * 5;
    
    for(int i=0;i<cities.size();i++){
        string city = "";
        for(char c: cities[i]){
            city += tolower(c);
        }
        
        auto it = find(cache.begin(), cache.end(), city);
        
        if(it != cache.end()){
            answer += 1;
            cache.erase(it);
        } else {
            answer += 5;
            if(cache.size() >= cacheSize){
                cache.pop_back();
            }
        }
        
        cache.push_front(city);
        
    }
    
    
    return answer;
}