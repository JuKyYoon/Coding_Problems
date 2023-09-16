#include <iostream>
#include <string>
using namespace std;
string s;
char str[11];
int alpha[27];
int ans = 0;
void pick(int cnt, int len) {
    if(cnt >= 2 && str[cnt-1] == str[cnt-2]) {
        return;
    }
    
    if(cnt == len) {
        // for(int i=0; i<len; i++) {
        //     cout << str[i];
        // } cout << '\n';
        ans++;
        return;
    }


    for(int i=0; i<26; i++) {
        if(alpha[i] != 0) {
            str[cnt] = i+'a';
            alpha[i]--;
            pick(cnt+1, len);
            alpha[i]++;
        }
    }
}



int main() {
    cin >> s;
    int len = s.length();
    for(int i=0; i<len; i++) {
        alpha[s[i] - 'a']++;
    }

    pick(0,len);
    cout << ans;
}