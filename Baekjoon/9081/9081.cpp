#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char str[105];
int main() {
    int n; cin >> n;

    while(n--) {
        cin >> str;
        int len = strlen(str);

        // 사전 순 역순 idx 찾기
        int idx = -1;
        for(int i=len-2; i>=0; i--) {
            if(str[i] < str[i+1]) {
                idx = i;
                break;
            }
        }

        if(idx==-1) { cout << str << "\n";}
        else{
            int swapIdx = -1;
            char swapChar = 'Z' + 1;

            for(int i=idx+1; i<len; i++) {
                if(str[i] > str[idx] && str[i] < swapChar) {
                    swapChar = str[i];
                    swapIdx = i;
                }
            }
            swap(str[idx], str[swapIdx]);
            sort(str+idx+1, str+len);
            cout << str << "\n";
        }
    }


}