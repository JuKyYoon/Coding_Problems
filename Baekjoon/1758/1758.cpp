#include <iostream>
#include <algorithm>
using namespace std;
int h[100001];
int main() {
    // 팁 ㅚ대
    int n; cin >> n;

    for(int i=0; i<n; i++) {
        cin >> h[i];
    }

    sort(h,h+n, greater<int>());
    long long ans = 0;
    for(int i=1; i<=n;i++) {
        if(h[i-1] + 1 - i > 0) {
            ans += (h[i-1] + 1 - i);
        }
    }
    cout << ans;
}