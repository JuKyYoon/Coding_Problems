#include <iostream>
using namespace std;
int score[101];
int main() {
    char a;
    int n,m,k; cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> score[i];
    }

    int maxscore = -1, ans_idx = -1;
    for(int i=0; i<m; i++) {
        int tmp_score = 0;
        cin >> k;

        for(int j=0; j<n; j++) {
            cin >> a;
            if(a == 'O') {
                tmp_score += score[j];
            } 
        }
        if(tmp_score > maxscore) {
            maxscore = tmp_score;
            ans_idx = k;
        } else if (tmp_score == maxscore) {
            ans_idx = min(ans_idx, k);
        }
    }
    cout << ans_idx << " " << maxscore;

}