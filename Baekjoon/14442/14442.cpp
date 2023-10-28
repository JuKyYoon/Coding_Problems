#include <iostream>
#include <queue>
using namespace std;
int memo[11][1001][1001];
char board[1001][1001];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int bfs(int n, int m, int k){
    queue<pair<pair<int,int>,int>> q;
    // 시작지점. 부순 벽 0개
    q.push({{0,0},0}); 

    // 최단 경로
    memo[0][0][0]=1;


    // BFS의 기초는 유지하고 있음. 가장 먼저 도착한 것이 최단이다.
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int break_wall = q.front().second;
        q.pop();

        if(y == n-1 && x== m-1){ return memo[break_wall][y][x]; }
        
        for(int i=0;i<4;i++){
            int dy = y + dir[i][0];
            int dx = x + dir[i][1];
            
            // 좌표 벗어남
            if(dy >=n || dy <0 || dx >= m || dx < 0){ continue; }

            // 벽 부수지 못함
            if(board[dy][dx] == '1' && break_wall == k){continue;}

            // 벽 부술수 있음.
            if(board[dy][dx] == '1' && memo[break_wall + 1][dy][dx] == 0){
                q.push({{dy, dx}, break_wall + 1});
                memo[break_wall + 1][dy][dx] = memo[break_wall][y][x]+1;
            }

            // 벽이랑 상관없음
            if(board[dy][dx] == '0' && memo[break_wall][dy][dx] == 0) {
                q.push({{dy,dx}, break_wall});
                memo[break_wall][dy][dx] = memo[break_wall][y][x]+1;
            }          
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> board[i];
    }
    cout << bfs(n,m,k);
}