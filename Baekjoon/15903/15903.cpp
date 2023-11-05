#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n,m; cin >> n >> m;
    long long a;
    // 카드 합체 M번
    // 점수를 가장 작게? = 그냥 최소끼리 더해줍니다,
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i=0; i<n; i++) {
        cin >> a;
        pq.push(a);
    }


    for(int i=0; i<m; i++) {
        long long k = pq.top();
        pq.pop();

        long long r = pq.top();
        pq.pop();
        // cout << k << " " << r << "\n";
        k += r;
        pq.push(k);
        pq.push(k);
    }

    long long ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}