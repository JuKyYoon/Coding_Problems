#include <iostream>
using namespace std;
int dp[10001][4];
int main() {


    // 1만 쓴거 2 쓴거 3 쓴거 나눠서 계산

    dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
    dp[2][1] = 1; dp[2][2] = 1; dp[2][3] = 0;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

    for(int i=4; i<=10000; i++) {

        int tmp = 0;

        dp[i][1] = dp[i-1][1]; // 유일한 경우
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];


    }

    int t,n; cin >> t;
    while(t--) {
        cin >> n; cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
}
