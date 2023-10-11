#include <iostream>
#include <cstring>
using namespace std;
int order[25];
int dp[25][25][25]; // [order][열린문][열린문] = 문 이동 최소 횟수
int m;

// 사용 순서, 열린문, 열린문
int solve(int o, int a, int b) {
    if(o >= m) { return 0; }
    if(dp[o][a][b] != -1) {return dp[o][a][b];}

    int &cnt = dp[o][a][b];
    cnt = 0;

    int door_idx = order[o]; // 사용하고 싶은 것.
    int left_cnt = solve(o+1, door_idx, b) + abs(a-door_idx);
    int right_cnt = solve(o+1, a, door_idx) + abs(b-door_idx);
    
    cnt = min(left_cnt, right_cnt);

    return cnt;
}




int main() {

    // 벽장이 있고, 벽장문은 n-2개.
    // 문은 옆으로 이동 가능
    // 사용할 벽장의 순서 주어지고, 벽장문 이동하는 최소 순서 찾기
    memset(dp, -1, sizeof(dp)); 
    int n,a,b,cnt=0;
    cin >> n >> a >> b;
    cin >> m;
    for(int i=0; i<m ; i++) {
        cin >> order[i];
    }

    
    cout << solve(0,a,b);
}