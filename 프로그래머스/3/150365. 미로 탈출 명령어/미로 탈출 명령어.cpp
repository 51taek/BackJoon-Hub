#include <string>
#include <vector>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dirs[4] = {'d', 'l', 'r', 'u'};

int a[52][52];

string answer = "impossible";
bool found = false;


void dfs(int idx, string s, int n, int m, int x, int y, int r, int c, int k){
    
    if(found) return;
    
    int dist = abs(r - x) + abs(c - y);
    if (dist > (k - idx)) return;
    if (((k - idx) - dist) % 2 != 0) return;
    
    if(idx == k && x == r && y == c){
        answer = s;
        found = true;
        return;
    }
        
    for(int dir=0;dir<4;dir++){
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        char ns = dirs[dir];
        
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        dfs(idx+1, s+ns, n, m, nx, ny, r, c, k);
        if(found) return;
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {

    answer = "impossible";
    found = false;
    dfs(0, "", n, m, x, y, r, c, k);
    
    return answer;
}