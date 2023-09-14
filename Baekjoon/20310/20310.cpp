#include <iostream>
#include <string>
using namespace std;
bool str[505];
int main() {
    string s; cin >> s;
    int len = s.length();

    // 앞에서 부터 절반의 1 제거
    // 뒤에서 부터 절반의 0 제거
    int zero=0, one=0;

    for(int i=0; i<len; i++) {
        if(s[i] == '0'){zero++;}
    } one = len - zero;
    one /= 2; zero /= 2;

    for(int i=0; i<len && one > 0 ; i++) {
        if(s[i] =='1') {one--; str[i]=1;}
    }

    for(int i=len-1; i>=0 && zero > 0; i--) {
        if(s[i] == '0') {zero--; str[i]=1;}
    }
    for(int i=0; i<len; i++) {
        if(str[i] == 0) {cout << s[i];}
    }
}