#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    if(b!=0) {return gcd(b, a%b);}
    else{return a;}
}

int lcm(int a, int b) {
    return (a*b)/gcd(a,b);
}

int main() {
    string s,t; cin >> s >> t;

    // f(s) = s 반복
    
    // 뭔가 최소 공배수 느낌이 남.
    // 길이가 같다면 전부 같아야 함.
    // 길이가 다르면 짧은 것을 반복시켜야 함. 얼마만큼? 최소 공배수 길이만큼
    // 아닌가? 그냥 s 반복시켜 t만들면 되는 건가? 검증 필요..

    int s_len = s.length(), t_len = t.length();

    if(s_len == t_len) {
        bool f = true;
        for(int i=0; i<s_len; i++) {
            if(s[i] != t[i]) {f = false; break;}
        }
        cout << f;

    } else {
        int lcm_len = lcm(s_len, t_len);
        bool f = true;
        int s_idx = 0, t_idx = 0;
        // cout << s << " " << t << "\n";
        for(int i=0; i<lcm_len; i++,s_idx++,t_idx++) {
            if(s_idx >= s_len) {s_idx = 0;}
            if(t_idx >= t_len) {t_idx = 0;}
            // cout << s_idx << " : " << t_idx << "\n";
            // cout << s[s_idx] << " : " <<  t[t_idx]<< "\n";
            if(s[s_idx] != t[t_idx]) {f= false; break;}
        }
        cout << f;
    }
}
/*
ababab
abab
*/