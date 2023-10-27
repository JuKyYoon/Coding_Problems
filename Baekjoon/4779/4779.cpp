#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool graph[555555];


void solve(int start_idx, int size, bool is_center) {
    // 가운데 문자열 공백
    if(is_center) { for(int i=start_idx; i<start_idx+size; i++) { graph[i] = 1; }}
    
    if(size == 1) {return;}



    // 3등분
    solve(start_idx, size/3, 0);
    solve((size/3) + start_idx, size/3, 1);
    solve((size/3*2) + start_idx, size/3, 0);
}





int main(){
    int n;
    while(cin >> n) {
        memset(graph, 0, sizeof(graph));
        int k = pow(3, n);
        solve(0, k, 0);

        for(int i=0; i<k; i++) {
            if(graph[i]) {cout << " ";}
            else{cout << "-";}
        }
        cout <<"\n";
    }
}