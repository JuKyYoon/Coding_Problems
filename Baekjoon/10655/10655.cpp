#include <iostream>
using namespace std;
int x[3];
int y[3];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,dist,jump_dist; cin >> n;
    // 중간에 있는 체크포인트들 중 하나를 건너뛸 때 최소거리
    // 체크포인트 거리는 다음거랑 다다음거 2개씩 구하기
    // 전체 최소거리이므로 그 차이가 가장 큰거 구하기
    // 그래서 전체거리에서 차이 가장 큰거 빼준다.
    int ans = 0;
    int max_diff=0;
    for(int i=1; i<=n; i++) {
        cin >> x[2] >> y[2];

        if(i >= 2) {
            dist = abs(x[2]-x[1]) + abs(y[2]-y[1]);
            ans += dist;
            // cout << "dist : " << dist << "\n";
        }
        if(i >= 3) {
            dist +=  abs(x[1]-x[0]) + abs(y[1]-y[0]);
            jump_dist = abs(x[2]-x[0]) + abs(y[2]-y[0]);
            // cout << i-2 << " idx jump : " << jump_dist << " " << dist << "\n";
            if(jump_dist < dist && dist-jump_dist > max_diff) {
                max_diff = dist-jump_dist;
            }

        }

        // 한 칸씩 밀어준다.
        x[0]=x[1]; y[0]=y[1];
        x[1]=x[2]; y[1]=y[2];

    }

    cout << ans - max_diff;

}