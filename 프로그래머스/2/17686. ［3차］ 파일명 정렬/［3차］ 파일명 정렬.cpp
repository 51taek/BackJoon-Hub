#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct File{
    string og;
    string head;
    int num;
};

string toLowerString(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}

File parseString(string s){
    int i = 0;
    int n = s.size();
    
    string head = "";
    string number = "";

    while (i < n && !isdigit(s[i])) {
        head += s[i];
        i++;
    }

    while (i < n && isdigit(s[i])) {
        number += s[i];
        i++;
    }

    return {s, toLowerString(head), stoi(number)};
}

bool compare(File a, File b){
    if(a.head != b.head) {
        return a.head < b.head;
    }
    
    return a.num < b.num;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> parsed;
    
    for(int i = 0; i < files.size(); i++){
        parsed.push_back(parseString(files[i]));
    }
    
    stable_sort(parsed.begin(), parsed.end(), compare);
    
    for(int i = 0; i < parsed.size(); i++){
        answer.push_back(parsed[i].og);
    }
    
    return answer;
}