#include <iostream>
#include <cstring>
#define MAX_NUM 34
using namespace std;
char num[44];
int dp[44];

int convertInt(char a, char b) {
    return ((a-'0') * 10) + (b-'0');
}


int main() {
    cin >> num;
    int len = strlen(num);
    
    // 뒤에서 부터 짜르면서 본다.
    // 0 주의

    // 2 7 1 2 3의 경우

    // 2 나머지 4개 + 27 나머지 3개
    //  위 공식이 정답이 된다. 즉 DP이용하면 된다.
    dp[0] = 1; // 기저값
    dp[1] = num[len-1] == '0' ? 0 : 1; // 맨 뒤에 숫자 1개는 1가지 경우
    
    if(len >= 2) {
        for(int i=2; i<=len; i++) {
            if(num[len - i] == '0') {
                dp[i] = 0; continue;
            }

            int tmp = convertInt(num[len-i], num[len-i+1]);
            // cout << tmp << "\n";
            if( tmp <= MAX_NUM) {
                dp[i] = dp[i-1]+dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }

        }
        // for(int i=1; i<=len; i++) {cout << dp[i] << " ";} 
    }

    cout << dp[len];
}