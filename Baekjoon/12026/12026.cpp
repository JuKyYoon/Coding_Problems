#include <iostream>
#include <cstring>
using namespace std;
char inputs[1001];
int dp[1001];
int main() {
    int n; cin >> n;
    cin >> inputs;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for(int i=0; i<n-1; i++) {
        if(dp[i] == -1) {continue;}
        for(int j=i+1; j<n; j++) {
            if((inputs[i] == 'B' && inputs[j] == 'O') 
            || (inputs[i] == 'O' && inputs[j] == 'J')
            || (inputs[i] == 'J' && inputs[j] == 'B')  ) {
                if(dp[j] == -1) {
                    dp[j] = dp[i] + ((j-i) * (j-i));
                } else {
                    dp[j] = min(dp[j],  dp[i] + ((j-i) * (j-i)));
                }
                // cout << i << " -> " << j << " : " << dp[j] << "\n";
            }

        }
    }

    cout << dp[n-1];

}