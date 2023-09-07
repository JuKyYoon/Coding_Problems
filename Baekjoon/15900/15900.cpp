#include <iostream>
#include <vector>

using namespace std;
vector<int> tree[500001];
int leaf_len = 0;
bool checked[500001];

void dfs(int here, int step) {

    checked[here] = 1;

    int size = tree[here].size();

    int cnt = 0;
    for(int i=0; i<size; i++) {
        int next = tree[here][i];
        if(!checked[next]) {
            cnt++;
            dfs(next, step+1);
        }
    }

    if(cnt == 0) {
        leaf_len += (step);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // 1번이 루트 노드, 리프 노드
    // 리프 노드에서 출발, 부모로 간다.노드 1개에 여러개 가능
    // 루트까지 가면 끝. 말 남아있으면 승리

    // 선은 성원, 형석이가 후

    int n,a,b; cin >> n;

    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);

    }
    
    // 1번에서 시작해서 리프 노드로 가는 횟수 구하자
    // 그 횟수가 홀수이면 선이 승, 짝수이면 후가 승

    dfs(1, 0); 
    cout << leaf_len << "\n";
    if(leaf_len % 2 != 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }

}