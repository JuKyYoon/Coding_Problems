#include <iostream>
#include <cstring>
using namespace std;
int dp[250];
int main() {
    int n,m,k; cin >> n >> m >> k;

    // 반드시 지나야 하는 곳을 기준으로 나눈다.
    // 각 번호는 자기자신 + 1 혹은 자기자신 + M만 가능.
    
    // 1->K
    bool flag = false;
    if(k == 0) { k = n*m; flag = true;}

    for(int i=1; i<=k; i++) {
        if(i <= m) { dp[i] = 1;}
        else {
            if( (i-1) % m != 0 && i-m>=1 ) {
                dp[i] = dp[i-1] + dp[i-m];
            }  else {
                dp[i] = 1;
            }
        }
    }
    if(flag){ cout << dp[k]; return 0;}
    int ans = dp[k];
    memset(dp, 0, sizeof(dp));

    // K를 좌측 꼭짓점으로 하는 가로 세로 구한다. 
    int height = (k-1) / m; // 맨 위가 0
    int width = (k-1) % m; // 맨 왼쪽이 0
    int dest = (n-height) * (m-width);
    int mm = m - width;
    for(int i=1; i<=dest; i++) {
        if(i <= mm) { dp[i] = 1;}
        else {
            if( (i-1) % mm != 0 && i-mm>=1 ) {
                dp[i] = dp[i-1] + dp[i-mm];
            }  else {
                dp[i] = 1;
            }
        }      
    }

    cout << ans * dp[dest];
}