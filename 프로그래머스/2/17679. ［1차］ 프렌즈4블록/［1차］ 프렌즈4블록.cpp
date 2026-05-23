#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

char a[50][50];

int n;
int m;

int remove(){
    int popNum = 0;
    bool b[50][50] = {};
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            
            if(a[i][j] == '.') continue;
            
            if(a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j+1]){
                b[i][j] = true;
                b[i+1][j] = true;
                b[i][j+1] = true;
                b[i+1][j+1] = true;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]){
                a[i][j] = '.';
                popNum++;
            }
        }
    }
    return popNum;
}

void drop(){
    for(int j = 0; j < m; j++){
        int bottom = n - 1;

        for(int i = n - 1; i >= 0; i--){
            if(a[i][j] != '.'){
                a[bottom][j] = a[i][j];

                if(bottom != i){
                    a[i][j] = '.';
                }

                bottom--;
            }
        }

        for(int i = bottom; i >= 0; i--){
            a[i][j] = '.';
        }
    }
}

int solution(int N, int M, vector<string> board) {
    int answer = 0;
    n = N;
    m = M;
    
    for(int i=0;i<board.size();i++){
        string s = board[i];
        for(int j=0;j<s.size();j++){
            a[i][j] = s[j];
        }
    }
    
    while(true){
        
        int num = remove();
        if(num == 0) break;
        else answer += num;
        drop();
    }
    
    
    
    return answer;
}