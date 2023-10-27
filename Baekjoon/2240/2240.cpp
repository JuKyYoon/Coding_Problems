#include <iostream>
using namespace std;
int dp[2][1005][33]; // [위치][초][움직인 횟수] = 받을 수 있는 자두 개수 
int main() {
    int t,w,a; cin >> t >> w;

    // 매 초마다 자두 떨어짐.
    // T초동안 최대 W번만 움직여서 받아먹음
    // 1초에 한번 이동? 여러번 가능

    // 맨 처음은 1번에 있음

    for(int i=1; i<=t; i++) {
        cin >> a;
        
        // j=0 일떄
        if(a == 1) {
            dp[0][i][0] = dp[0][i-1][0] + 1;
            // dp[1][i][0] = dp[0][i-1][0]; 불가능
        } else {
            dp[0][i][0] = dp[0][i-1][0];
            // dp[1][i][0] = dp[0][i-1][0] + 1;
        }


        for(int j=1; j<=w; j++) {
            // 1번에 떨어짐
            if(a == 1) {
                dp[0][i][j] = max(dp[0][i-1][j] + 1, dp[1][i-1][j-1] + 1); // 1번 위치
                dp[1][i][j] = max(dp[0][i-1][j-1], dp[1][i-1][j]); // 2번 위치

            } else {
                // 2번에 떨어짐
                dp[0][i][j] = max(dp[0][i-1][j], dp[1][i-1][j-1]); // 1번 위치
                dp[1][i][j] = max(dp[0][i-1][j-1] + 1, dp[1][i-1][j] + 1); // 2번 위치
            }
        }

    }



    // for(int i=1; i<=t; i++) {
    //     for(int j=0; j<=w; j++) {
    //         cout << j << " move : " << dp[0][i][j] << " " << dp[1][i][j] << "\n";
    //     }
    //     cout << "-----------\n";
    // }


    int ans = 0;
    for(int i=0; i<= w; i++) {
        ans = max(ans, max(dp[0][t][i], dp[1][t][i]));
    }
    cout << ans;
}