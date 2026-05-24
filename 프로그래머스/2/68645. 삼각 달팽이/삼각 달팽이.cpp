#include <string>
#include <vector>

using namespace std;

int dx[3] = {1, 0, -1};
int dy[3] = {0, 1, -1};

vector<int> solution(int n) {
    vector<int> answer;
    
     vector<vector<int>> board(n, vector<int>(n, 0));
    
    int r = -1;
    int c = 0;
    int dir = 0;
    
    int total = n * (n + 1) / 2;
    
    for(int i=1;i<=total;i++){
        int nr = r + dx[dir];
        int nc = c + dy[dir];
        
        if(nr < 0 || nc < 0 || nr >= n || nc >= n || board[nr][nc] != 0){
            dir = (dir+1) % 3;
            nr = r+ dx[dir];
            nc = c + dy[dir];
        }
        
        board[nr][nc] = i;
        r = nr;
        c = nc;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(board[i][j]);
        }
    }
    
    return answer;
}