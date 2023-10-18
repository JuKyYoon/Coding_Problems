#include <iostream>
typedef long long ll;
using namespace std;
ll dp[101];
int main() {
    int n; cin >> n;

    // 버퍼 있는 경우, 없는 경우 생갹해야 함. 무엇을 복사할거냐
    // 웬만하면 붙여넣기하면 최대
    // 3번째 전꺼 선택 복사 붙여넣기
    // 4번째 전꺼 선택 복사 붙여넣기 붙여넣기
    // 5번째 전꺼 선택 복사 붙여넣기 붙여넣기 붙여넣기
    

    for(ll i=1; i<=n; i++) { // 버튼을 누른 횟수
        dp[i] = dp[i-1] + 1;
        for(ll j=3; j<i; j++) {
            dp[i] = max(dp[i], dp[i-j]*(j-1));
        }

    }

    cout << dp[n];
}