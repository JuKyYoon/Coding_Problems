#include <iostream>
#include <string>
using namespace std;

int solve(int L, int O, int V, int E) {
    return ((L+O) * (L+V) * (L+E) * (O+V) * (O+E) * (V+E)) % 100;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,l=0,o=0,v=0,e=0;
    string name,t,ans=""; cin >> name;
    int max_score = -1;
    int len = name.length();
    for(int i=0; i<len; i++) {
        if(name[i] == 'L') {l++;}
        else if(name[i] == 'O') {o++;}
        else if(name[i] == 'V') {v++;}
        else if(name[i] == 'E') {e++;}

    }
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp[4] = {0,0,0,0};
        cin >> t;
        len = t.length();
        for(int j=0; j<len; j++) {
            if(t[j] == 'L') {tmp[0]++;}
            else if(t[j] == 'O') {tmp[1]++;}
            else if(t[j] == 'V') {tmp[2]++;}
            else if(t[j] == 'E') {tmp[3]++;}
        }

        int score = solve(l+tmp[0], o+tmp[1], v+tmp[2], e+tmp[3]);
        if(max_score < score) {
            max_score = score;
            ans = t;
        } else if (max_score == score) {
            if(ans > t) {
                ans = t;
            }
        }
    }
    cout << ans;
}