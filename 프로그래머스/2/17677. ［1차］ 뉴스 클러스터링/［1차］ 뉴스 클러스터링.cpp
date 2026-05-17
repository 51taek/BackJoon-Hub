#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> a;
    vector<string> b;
    
    string ns1 = "";
    string ns2 = "";
    
    for(int i = 0; i + 1 < str1.size(); i++){
        char c1 = str1[i];
        char c2 = str1[i + 1];

        if(isalpha(c1) && isalpha(c2)){
            string s = "";
            s += toupper(c1);
            s += toupper(c2);
            a.push_back(s);
        }
    }

    for(int i = 0; i + 1 < str2.size(); i++){
        char c1 = str2[i];
        char c2 = str2[i + 1];

        if(isalpha(c1) && isalpha(c2)){
            string s = "";
            s += toupper(c1);
            s += toupper(c2);
            b.push_back(s);
        }
    }
    
    set<string> se;
    map<string,int> m1;
    map<string,int> m2;
    
    for(string s: a){
        se.insert(s);
        m1[s]++;
    }
    for(string s: b){
        se.insert(s);
        m2[s]++;
    }
    
    int hop = 0;
    int gyo = 0;
    
    for(string s: se){
        gyo += min(m1[s],m2[s]);
        hop += max(m1[s],m2[s]);
    }
    
    if(hop == 0) return 65536;

    return gyo * 65536 / hop;
}