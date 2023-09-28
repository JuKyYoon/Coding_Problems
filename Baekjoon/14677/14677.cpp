#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
char med[1600];
char times[3] = {'B', 'L', 'D'};
bool visited[1600][1600];
int main() {
    int n; cin >> n;
    cin >> med;
    int len = strlen(med);

    // 아침,점심,저녁 구분 ,  그리고 맨앞, 맨뒤 인덱스
    queue<pair<int, pair<int,int>>> q;
    visited[0][len-1] = 1;

    if(med[0] == 'B') {
        q.push({ 1, { 1, len-1}});
        visited[1][len-1] = 1;
    }

    if(med[len-1] == 'B') {
        q.push({ 1, { 0, len-2}});
        visited[0][len-2] = 1;
    }

    int ans = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int t = q.front().first;
            int front = q.front().second.first;
            int back = q.front().second.second;
            q.pop();
            
            if(front > back) { continue;}

            if(med[front] == times[t] && !visited[front+1][back]) {
                q.push({ (t+1)%3, {front+1, back}});
                visited[front+1][back] = 1;
            }

            if(med[back] == times[t] && !visited[front][back-1]) {
                q.push({ (t+1)%3, {front, back-1}});
                visited[front][back-1] = 1;
            }
        }
        ans++;
    }

    cout << ans;
}