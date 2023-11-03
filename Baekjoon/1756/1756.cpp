#include <iostream>
using namespace std;
int oven[300001];
int main() {

    // 오븐 깊이 d 반죽 개수 n
    // 오븐의 지름
    int d,n,pizza; cin >> d >> n;
    bool ans = 1;
    for(int i=0; i<d; i++) {
        cin >> oven[i];
        if(i > 0 && oven[i] > oven[i-1]) {
            oven[i] = oven[i-1];
        }
    }

    // 피자 순서대로 오븐에 들어감.
    // 가장 깊은 곳 idx 구해준다.
    int idx = d-1;
    for(int i=0; i<n; i++) {
        cin >> pizza;

        while(idx >= 0 && oven[idx] < pizza) {idx--;}
        
        if(idx < 0) {ans = 0; break;}
        else{
            // 피자 넣는다.
            idx-=1;
        }
    }

    if(!ans) {cout << 0;}
    else {cout << idx+2;}

}