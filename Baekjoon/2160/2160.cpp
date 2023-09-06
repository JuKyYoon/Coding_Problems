#include <iostream>
using namespace std;
char paint[51][10][10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<5; j++) {
            cin >> paint[i][j];
        }
    }

    pair<int,int> ans = {-1,-1};
    int min_diff=2e9;
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            int diff = 0;
            
            for(int y=0; y<5; y++) {
                for(int x=0;x<7;x++) {
                    if(paint[i][y][x] != paint[j][y][x]) {diff++;}
                }
            }

            if(diff < min_diff) {
                min_diff = diff;
                ans = {i,j};
            }
        }
    }
    cout << ans.first << " " << ans.second;
}