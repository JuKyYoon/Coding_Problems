#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int p,w; cin >> p >> w;
    getchar();
    getline(cin, s);
    int len = s.length();
    int ans = 0, before = -1;
    for(int i=0; i<len; i++) {
        if(s[i] == ' ') {
            ans += p;
            before = -1;
        } else {
            int here = (s[i] - 'A') / 3;
            int click = (s[i] - 'A') % 3;

            if(s[i] >= 'W') {
                here = 7;
                if(s[i] == 'W') {click = 0;}
                else if(s[i] == 'X') {click = 1;}
                else if(s[i] == 'Y') {click = 2;}
                else if(s[i] == 'Z') {click = 3;}
            } else if (s[i] >= 'T') {
                here = 6;
                if(s[i] == 'T') {click = 0;}
                else if(s[i] == 'U') {click = 1;}
                else if(s[i] == 'V') {click = 2;}
            } else if (s[i] >= 'P') {
                here = 5;
                if(s[i] == 'P') {click = 0;}
                else if(s[i] == 'Q') {click = 1;}
                else if(s[i] == 'R') {click = 2;}
                else if(s[i] == 'S') {click = 3;}
            }

            if(before == here) {
                ans +=w;
            }

            ans += ((click+1)*p);
            before = here;
        }
    }
    cout << ans;
}