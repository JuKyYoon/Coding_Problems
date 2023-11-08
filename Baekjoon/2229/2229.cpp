#include <iostream>
using namespace std;
int students[1001];
int dp[1001]; // i번까지 봤을 때 최댓값
int main() {
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> students[i];
    }
    int maxScore = -1, minScore = 2e9;

    for(int i=2; i<=n; i++) {
        minScore = students[i];
        maxScore = students[i];
        for(int j=i-1;j>=0;j--) {
            maxScore = max(maxScore, students[j+1]);
            minScore = min(minScore, students[j+1]);
            dp[i] = max(dp[i], dp[j] + maxScore - minScore);
        }
    }

    cout << dp[n];

    // 각각의 조가 잘 짜여진 정도를 구해야 함
    // 1명인 경우 0, 가장 점수 높은 - 가장 점수 낮은
    // 즉, 차이 많이 나야 함?
    // 조가 잘 짜여진 정도의 최댓값

    // 나이순 정렬
    // 2 5 7 1 3 4 8 6 9 3
    // 저기서 연속되는 부분집합 만든다.




}