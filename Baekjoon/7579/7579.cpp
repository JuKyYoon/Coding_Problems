#include <iostream>
using namespace std;
int mem[100],cost[100]; 
int dp[10001]; // 100 * 100 [cost] = 확보가능한 메모리
int main() {
    // 스마트폰 앱 : 현재 메모리, 재활성비용
    // 메모리 M바이트를 확보하기 위한 비활성화 최소의 비용.
    int allCost = 0;
    int N,M; cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> mem[i];
    }
    for(int i=0; i<N; i++) {
        cin >> cost[i];
        allCost += cost[i]; 
    }

    // 비용 소모해서 메모리 얻기
    for(int i=0; i<N; i++) {
        // 비용 = j
        for(int j=allCost; j >= cost[i] ; j--) {
            // i번째 앱까지 봤을 때 j cost 사용 가능한가
            dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
            // cout << dp[j] << " ";
        }
        // cout << "\n";
    }

    int ans = 2e9;
    for(int i=0; i<=allCost; i++) {
        if(dp[i] >= M) {ans = i; break;}
    }

    cout << ans;
}