#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int board[102][102];

int n, m;

 int main(){

   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> n >> m;

   for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
       board[i][j] = INF;
     }
   }
   
   for(int i=0;i<m;i++){
     int a, b, cost;
     cin >> a >> b >> cost;
     board[a][b] = min(board[a][b], cost);
   }

   for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
       if(i==j) board[i][j] = 0;
     }
   }

   for(int k=1;k<=n;k++)
     for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
         board[i][j] = min(board[i][j], board[i][k] + board[k][j]);


   for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
       if(board[i][j] == INF) cout << 0 << " ";
       else cout << board[i][j] << " ";
     }
     cout << "\n";
   }
 }