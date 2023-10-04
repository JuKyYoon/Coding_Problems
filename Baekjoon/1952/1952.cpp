#include <iostream>
using namespace std;
bool checked[101][101];
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int main() {
    int m,n; cin >> m >> n;
    checked[0][0] = 1;
    int ans = 0,y=0,x=0,d=0; 
    while(1) {
        int dy = y + dir[d][0];
        int dx = x + dir[d][1];
        if(checked[dy][dx] || dy >= m || dx >= n || dy < 0 || dx < 0) {
            d++; d%=4;
            dy = y + dir[d][0];
            dx = x + dir[d][1];
            ans++;
        }

        if(checked[dy][dx] || dy >= m || dx >= n || dy < 0 || dx < 0) {ans-= 1; break;}
        // cout << dy << " " << dx << "\n";
        y=dy; x=dx;
        checked[dy][dx] = 1;
    }
    cout << ans;
}