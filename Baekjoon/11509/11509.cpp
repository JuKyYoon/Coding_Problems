#include <iostream>
using namespace std;
int h[1000001];
int arrow[1000001];
int main() {
    int n;cin >> n;
    for(int i=0; i<n; i++) {
        cin >> h[i];
    }

    // 풍선이 N개 있고, 왼쪽에서 오른쪽으로 터트림.
    // 높이는 임의로 선택. 선택된 높이 H에서 화살은 풍선 만날때까지 왼쪽에서 오른쪼긍로 이동.
    // 화살이 풍선 만나면 높이 -1
    // 적은 화살로 모든 풍선터뜨리기
    // 풍선 높이 주어짐.

    // 차이 1나는 내림차순 구하기.
    // 대충 하면 최대 N제곱
    // 화살 위치를 확인한다.

    int ans = 0;
    for(int i=0; i<n; i++) {
        int now_height = h[i];
        
        // 현재 높이에 화살이 없다.
        if(arrow[now_height] == 0) {
            ans++;

        } else {
            // 현재 높이에 화살이 있다/
            arrow[now_height]--;
        }

        // 높이 -1에 화살 추가
        if(now_height-1 != 0) {
            arrow[now_height-1]++;
        }
    }
    cout << ans;
}