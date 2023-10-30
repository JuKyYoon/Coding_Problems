#include <iostream>
using namespace std;

int ans = 0;

void solve(int n, int cnt, int k) {
    if(n == cnt) {

        if(k%3 == 0) {ans++;}
        return ;
    }

    for(int i=0; i<=2; i++) {
        if(cnt == 0 && i == 0) {continue;}
        solve(n, cnt+1, (k*10) + i);
    }
}



int main() {
    int n; cin >> n;
    solve(n, 0, 0);

    cout << ans;
}