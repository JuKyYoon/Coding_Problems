#include <iostream>
using namespace std;
int weights[35];
int bead[10];
bool weight_dp[15001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int weight_cnt, bead_cnt; cin >> weight_cnt;
    for(int i=0; i<weight_cnt; i++) {
        cin >> weights[i];
    }

    weight_dp[weights[0]] = 1;
    for(int i=1; i<weight_cnt; i++) {
        for(int j=15000; j>=0; j--){
            if(j-weights[i] >= 1 && weight_dp[j-weights[i]] == 1) {
                weight_dp[j] = 1;
            }
        }
        weight_dp[weights[i]] = 1;
    }

    cin >> bead_cnt;
    weight_dp[0] = 1;

    // for(int i=0; i<15; i++) {
    //     cout << weight_dp[i] << " ";
    // }
    // cout << "\n--------\n";
    for(int i=0; i<bead_cnt; i++) {
        cin >> bead[i];
    }

    for(int i=0; i<bead_cnt; i++) {
        bool ans = 0;
        for(int j=15000; j>=0; j--) {
            if(weight_dp[j] && j-bead[i] >= 0 && weight_dp[j-bead[i]]) {
                ans = 1; break;
            }
        }
        if(ans) { cout << "Y ";}
        else { cout << "N ";}
    }

    
}