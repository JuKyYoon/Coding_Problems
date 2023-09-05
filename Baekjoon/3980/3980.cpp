#include <iostream>
#include <cstring>
using namespace std;
int s[11][11];
bool position[11];
int ans = -1;
void solve(int player, int fit_sum) {
    if(player == 11) {
        ans = max(ans, fit_sum);
        return ;
    }

    for(int i=0; i<11; i++) {
        if(!position[i] && s[player][i] > 0) {
            position[i] = 1;
            solve(player+1, fit_sum + s[player][i]);
            position[i] = 0;
        }
    }
}

void init() {
    ans = -1;
    memset(position, 0, sizeof(position));
}


int main() {
    int c; cin >> c;

    while(c--) {
        init();
        for(int i=0; i<11; i++) {
            for(int j=0; j<11; j++) {
                cin >> s[i][j];
            }
        }

        // 재귀로 1개씩 선택. 브루트 포스
        solve(0, 0);
        cout << ans << "\n";
    }
}
