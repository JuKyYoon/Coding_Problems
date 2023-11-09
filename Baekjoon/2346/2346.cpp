#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,b; cin >> n;
    deque<pair<int,int>> dq;
    for(int i=0; i<n; i++) {
        cin >> b;
        dq.push_back({i+1,b});
    }


    int k = dq.front().second;
    dq.pop_front();
    cout << 1 << " ";
    while(!dq.empty()) {
        if( k > 0) {
            k--;
            while(k--) {
                int i = dq.front().first;
                int m = dq.front().second;
                dq.pop_front();
                dq.push_back({i,m});
            }

        } else {
            while(k!=0) {
                k++;
                int i = dq.back().first;
                int m = dq.back().second;
                dq.pop_back();
                dq.push_front({i,m});
            }
        }
        k = dq.front().second;
        cout << dq.front().first << " ";
        dq.pop_front();
    }
}