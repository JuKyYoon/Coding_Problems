#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,t;
    while(cin >> s) {
        cin >> t;       
        // s가 t안에 있어야 함.
        // t 읽으면서 s 찾기
        int s_idx = 0, tlen = t.length();
        for(int i=0; i<tlen; i++) {
            if(t[i] == s[s_idx]) {s_idx++;}
        }                                 

        if(s_idx == s.length()){
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }                      
    }
}