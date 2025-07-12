#include <string>
#include <vector>

using namespace std;

char a[5] = {'A', 'E', 'I', 'O', 'U'};
int cnt;
int answer;

void dfs(string s, string word){
    int l = s.size();
    if(l > 0){
        cnt++;
        if(s==word){
            answer = cnt;
        }
    }
    if(l==5) return;
    
    for(int i=0;i<5;i++){
        string tmp = s;
        tmp += a[i];
        dfs(tmp, word);
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}